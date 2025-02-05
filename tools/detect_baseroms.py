import hashlib
import os
import sys
import subprocess

XDG_DATA_DIR = os.environ.get("XDG_DATA_HOME") or "~/.local/share"
ROMS_DIR = os.path.expanduser(os.path.join(XDG_DATA_DIR, "HackerSM64"))

sha1_LUT = {
    "eu": "4ac5721683d0e0b6bbb561b58a71740845dceea9",
    "jp": "8a20a5c83d6ceb0f0506cfc9fa20d8f438cafe51",
    "sh": "3f319ae697533a255a1003d09202379d78d5a2e0",
    "us": "9bef1128717f958171a4afac3ed78ee2bb4e86ce",
}

sha1_swapLUT = {
    "eu": "d80ee9eeb6454d53a96ceb6ed0aca3ffde045091",
    "jp": "1d2579dd5fb1d8263a4bcc063a651a64acc88921",
    "sh": "2a2b85e94581545ca3c05b8f864b488b141a8a1f",
    "us": "1002dd7b56aa0a59a9103f1fb3d57d6b161f8da7",
}

def compute_sha1(file_path):
    """Compute SHA-1 hash of a file"""
    try:
        with open(file_path, "rb") as f:
            sha1 = hashlib.sha1()
            while chunk := f.read(8192):  # Read in chunks
                sha1.update(chunk)
            return sha1.hexdigest()
    except Exception as e:
        print(f"Error reading {file_path}: {e}", file=sys.stderr)
        return None

def get_rom_candidates():
    """Find and verify ROMs in the current directory and ROMS_DIR."""
    fileArray = [f for f in os.listdir(os.getcwd()) if os.path.isfile(f)]
    
    if os.path.exists(ROMS_DIR):
        fileArray += [os.path.join(ROMS_DIR, f) for f in os.listdir(ROMS_DIR) if os.path.isfile(os.path.join(ROMS_DIR, f))]

    foundVersions = {}

    for f in fileArray:
        sha1sum = compute_sha1(f)
        if not sha1sum:
            continue

        for k, v in sha1_LUT.items():
            if v == sha1sum:
                foundVersions[k] = f

        for k, v in sha1_swapLUT.items():
            if v == sha1sum:  # ROM is byte-swapped
                swapped_rom = f"/tmp/baserom.{k}.swapped.z64"
                try:
                    subprocess.run(
                        ["dd", "conv=swab", f"if={f}", f"of={swapped_rom}"],
                        stderr=subprocess.PIPE,
                        check=True,
                    )
                    foundVersions[k] = swapped_rom
                except subprocess.CalledProcessError as e:
                    print(f"Failed to swap {f}: {e}", file=sys.stderr)

    return foundVersions

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} version (us jp eu sh)")
        sys.exit(1)
    
    version = sys.argv[1]
    gamelist = get_rom_candidates()

    if version in gamelist:
        print(gamelist[version])
    else:
        print(f"No valid ROM found for version {version}", file=sys.stderr)
        sys.exit(1)
