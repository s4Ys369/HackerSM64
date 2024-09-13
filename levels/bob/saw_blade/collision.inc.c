const Collision saw_blade_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(0, 600, 38),
	COL_VERTEX(424, 424, -37),
	COL_VERTEX(0, 600, -37),
	COL_VERTEX(424, 424, 38),
	COL_VERTEX(600, 0, -38),
	COL_VERTEX(600, 0, 38),
	COL_VERTEX(424, -424, -38),
	COL_VERTEX(424, -424, 37),
	COL_VERTEX(0, -600, -38),
	COL_VERTEX(0, -600, 37),
	COL_VERTEX(-424, -424, -38),
	COL_VERTEX(-424, -424, 37),
	COL_VERTEX(-600, 0, -38),
	COL_VERTEX(-600, 0, 38),
	COL_VERTEX(-424, 424, -37),
	COL_VERTEX(-424, 424, 38),
	COL_TRI_INIT(SURFACE_HURT, 24),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 1),
	COL_TRI(5, 6, 4),
	COL_TRI(7, 8, 6),
	COL_TRI(9, 10, 8),
	COL_TRI(11, 12, 10),
	COL_TRI(13, 14, 12),
	COL_TRI(15, 2, 14),
	COL_TRI(0, 3, 1),
	COL_TRI(3, 5, 4),
	COL_TRI(5, 7, 6),
	COL_TRI(7, 9, 8),
	COL_TRI(9, 11, 10),
	COL_TRI(11, 13, 12),
	COL_TRI(5, 3, 0),
	COL_TRI(0, 15, 13),
	COL_TRI(13, 11, 9),
	COL_TRI(9, 7, 5),
	COL_TRI(13, 15, 14),
	COL_TRI(15, 0, 2),
	COL_TRI(14, 2, 1),
	COL_TRI(1, 4, 6),
	COL_TRI(6, 8, 10),
	COL_TRI(10, 12, 14),
	COL_TRI_INIT(SURFACE_DEFAULT, 4),
	COL_TRI(13, 9, 5),
	COL_TRI(6, 10, 14),
	COL_TRI(5, 0, 13),
	COL_TRI(14, 1, 6),
	COL_TRI_STOP(),
	COL_END()
};
