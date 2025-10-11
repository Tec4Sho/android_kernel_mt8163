/*
 * Copyright (c) 2014-2015 MediaTek Inc.
 * Author: Tianping.Fang <tianping.fang@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#if defined(__GNUC__)
#pragma GCC system_header
#endif
#ifndef __MT6397_RTC_MISC_H__
#define __MT6397_RTC_MISC_H__
#include <linux/types.h>
#ifndef RTC_GPIO_USER_WIFI
#define RTC_GPIO_USER_WIFI	8
#endif
#ifndef RTC_GPIO_USER_GPS
#define RTC_GPIO_USER_GPS	 9
#endif
#ifndef RTC_GPIO_USER_BT
#define RTC_GPIO_USER_BT	10
#endif
#ifndef RTC_GPIO_USER_FM
#define RTC_GPIO_USER_FM	11
#endif
#ifndef RTC_GPIO_USER_PMIC
#define RTC_GPIO_USER_PMIC	12
#endif
#ifdef CONFIG_MT6397_MISC
extern void mtk_misc_mark_fast(void);
extern void mtk_misc_mark_recovery(void);
extern bool mtk_misc_low_power_detected(void);
extern bool mtk_misc_crystal_exist_status(void);
extern int mtk_misc_set_spare_fg_value(u32 val);
extern u32 mtk_misc_get_spare_fg_value(void);
extern void rtc_gpio_enable_32k(u16 user);
extern void rtc_gpio_disable_32k(u16 user);
#else
#define mtk_misc_mark_fast()			do {} while (0)
#define mtk_misc_mark_recovey()			do {} while (0)
#define mtk_misc_low_power_detected()		({ 0; })
#define mtk_misc_crystal_exist_status()		({ 1; })
#define mtk_misc_set_spare_fg_value(val)	({ 0; })
#define mtk_misc_get_spare_fg_value()		({ 0; })
#define rtc_gpio_enable_32k(user)		do {} while (0)
#define rtc_gpio_disable_32k(user)		do {} while (0)
#endif
#ifndef CONFIG_MTK_RTC
extern void rtc_mark_fast(void);
extern void rtc_mark_clear_lprst(void);
extern void rtc_mark_enter_lprst(void);
extern void rtc_mark_enter_sw_lprst(void);
extern u16 rtc_rdwr_uart_bits(u16 *val);
extern void rtc_bbpu_power_down(void);
extern void rtc_read_pwron_alarm(struct rtc_wkalrm *alm);
extern int get_rtc_spare_fg_value(void);
extern int set_rtc_spare_fg_value(int val);
extern void rtc_irq_handler(void);
extern bool crystal_exist_status(void);
extern bool rtc_lprst_detected(void);

#ifndef rtc_mark_fast
#define rtc_mark_fast()  ({ 0; })
#endif
#ifndef rtc_mark_clear_lprst
#define rtc_mark_clear_lprst()  ({ 0; })
#endif
#ifndef rtc_mark_enter_lprst
#define rtc_mark_enter_lprst()  ({ 0; })
#endif
#ifndef rtc_mark_enter_sw_lprst
#define rtc_mark_enter_sw_lprst()  ({ 0; })
#endif
#ifndef rtc_rdwr_uart_bits
#define rtc_rdwr_uart_bits(val)  ({ 0; })
#endif
#ifndef rtc_bbpu_power_down
#define rtc_bbpu_power_down()  ({ 0; })
#endif
#ifndef rtc_read_pwron_alarm
#define rtc_read_pwron_alarm(alm)  ({ 0; })
#endif
#ifndef get_rtc_spare_fg_value
#define get_rtc_spare_fg_value()  ({ 0; })
#endif
#ifndef set_rtc_spare_fg_value
#define set_rtc_spare_fg_value(val)  ({ 0; })
#endif
#ifndef rtc_irq_handler
#define rtc_irq_handler()  ({ 0; })
#endif
#ifndef crystal_exist_status
#define crystal_exist_status()  ({ 0; })
#endif
#ifndef rtc_lprst_detected
#define rtc_lprst_detected()  ({ 0; })
#endif
#endif
#endif /* __MT6397_RTC_MISC_H__ */

