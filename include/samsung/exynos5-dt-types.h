#ifndef _EXYNOS5_DT_H_
#define _EXYNOS5_DT_H_

/* Matches exynos5_type_info array (exynos5_info) */
enum {
	EXYNOS5_BOARD_GENERIC,

	EXYNOS5_BOARD_ARNDALE_OCTA,
	/* All Odroid types must be continuous */
	EXYNOS5_BOARD_ODROID_XU3,
	EXYNOS5_BOARD_ODROID_XU3_REV01,
	EXYNOS5_BOARD_ODROID_XU3_REV02,
	EXYNOS5_BOARD_ODROID_XU4_REV01,
	EXYNOS5_BOARD_ODROID_HC1_REV01,
	EXYNOS5_BOARD_ODROID_HC2_REV01,
	EXYNOS5_BOARD_ODROID_UNKNOWN,

	EXYNOS5_BOARD_COUNT,
};

/* Description of each Exynos542x board */
struct exynos5_type_info {
	const char *name;
};

/* Revision information for Exynos5422 Odroid boards */
struct odroid_rev_info {
	int board_type;
	int board_rev;
	int adc_val;
};

bool board_is_generic(void);
bool board_is_odroidxu3(void);
bool board_is_odroidxu4(void);
bool board_is_odroidhc1(void);
bool board_is_odroidhc2(void);

#endif
