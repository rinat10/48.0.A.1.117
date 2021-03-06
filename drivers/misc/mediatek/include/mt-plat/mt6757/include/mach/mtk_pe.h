/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef _CUST_PE_H_
#define _CUST_PE_H_

/* PE+/PE+20 */
#define TA_START_BATTERY_SOC	1
#define TA_STOP_BATTERY_SOC	85
#define TA_AC_12V_INPUT_CURRENT CHARGE_CURRENT_1250_00_MA //ori 3200mA
#define TA_AC_9V_INPUT_CURRENT	CHARGE_CURRENT_1500_00_MA //ori 3200mA
#define TA_AC_7V_INPUT_CURRENT	CHARGE_CURRENT_1600_00_MA //ori 3200mA
//CEI comment start//
#if defined(CONFIG_BUILD_REDWOOD) // redwood
#define TA_AC_CHARGING_CURRENT	CHARGE_CURRENT_2432_00_MA //ori 3200mA
#elif defined(CONFIG_BUILD_TEAK) // teak, sync redwood first
//0.7C=2401mA, let ibat=2400 to support bq=2368mA and rt=2400mA
#define TA_AC_CHARGING_CURRENT	CHARGE_CURRENT_2400_00_MA //ori 3200mA
#else // hinoki
#define TA_AC_CHARGING_CURRENT	CHARGE_CURRENT_1875_00_MA //ori 3200mA
#endif
//CEI comment end//
#define TA_9V_SUPPORT
#define TA_12V_SUPPORT

/* Ichg threshold for leaving PE+/PE+20 */
#define PEP20_ICHG_LEAVE_THRESHOLD 1000 /* mA */
#define PEP_ICHG_LEAVE_THRESHOLD 1000 /* mA */

typedef struct _pep20_profile {
	unsigned int vbat;
	unsigned int vchr;
} pep20_profile_t, *p_pep20_profile_t;

/* For PE+20, default VBUS V.S. VBAT table (generated according to BQ25896) */
#define VBAT3400_VBUS CHR_VOLT_08_000000_V
#define VBAT3500_VBUS CHR_VOLT_08_500000_V
#define VBAT3600_VBUS CHR_VOLT_08_500000_V
#define VBAT3700_VBUS CHR_VOLT_09_000000_V
#define VBAT3800_VBUS CHR_VOLT_09_000000_V
#define VBAT3900_VBUS CHR_VOLT_09_000000_V
#define VBAT4000_VBUS CHR_VOLT_09_500000_V
#define VBAT4100_VBUS CHR_VOLT_09_500000_V
#define VBAT4200_VBUS CHR_VOLT_10_000000_V
#define VBAT4300_VBUS CHR_VOLT_10_000000_V

#endif /* _CUST_PE_H_ */
