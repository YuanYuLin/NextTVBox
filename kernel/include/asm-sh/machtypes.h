/*
 * Automagically generated, don't touch.
 */
#ifndef __ASM_SH_MACHTYPES_H
#define __ASM_SH_MACHTYPES_H

/*
 * We'll use the following MACH_xxx defs for placeholders for the time
 * being .. these will all go away once sh_machtype is assigned per-board.
 *
 * For now we leave things the way they are for backwards compatibility.
 */

/* Mach types */
#ifdef CONFIG_SH_SOLUTION_ENGINE
  #define MACH_SE		1
#else
  #define MACH_SE		0
#endif
#ifdef CONFIG_SH_HIGHLANDER
  #define MACH_HIGHLANDER		1
#else
  #define MACH_HIGHLANDER		0
#endif
#ifdef CONFIG_SH_RTS7751R2D
  #define MACH_RTS7751R2D		1
#else
  #define MACH_RTS7751R2D		0
#endif
#ifdef CONFIG_SH_RSK
  #define MACH_RSK		1
#else
  #define MACH_RSK		0
#endif
#ifdef CONFIG_HD64461
  #define MACH_HD64461		1
#else
  #define MACH_HD64461		0
#endif
#ifdef CONFIG_SH_7206_SOLUTION_ENGINE
  #define MACH_7206SE		1
#else
  #define MACH_7206SE		0
#endif
#ifdef CONFIG_SH_7343_SOLUTION_ENGINE
  #define MACH_7343SE		1
#else
  #define MACH_7343SE		0
#endif
#ifdef CONFIG_SH_7619_SOLUTION_ENGINE
  #define MACH_7619SE		1
#else
  #define MACH_7619SE		0
#endif
#ifdef CONFIG_SH_7721_SOLUTION_ENGINE
  #define MACH_7721SE		1
#else
  #define MACH_7721SE		0
#endif
#ifdef CONFIG_SH_7722_SOLUTION_ENGINE
  #define MACH_7722SE		1
#else
  #define MACH_7722SE		0
#endif
#ifdef CONFIG_SH_7724_SOLUTION_ENGINE
  #define MACH_7724SE		1
#else
  #define MACH_7724SE		0
#endif
#ifdef CONFIG_SH_7751_SOLUTION_ENGINE
  #define MACH_7751SE		1
#else
  #define MACH_7751SE		0
#endif
#ifdef CONFIG_SH_7780_SOLUTION_ENGINE
  #define MACH_7780SE		1
#else
  #define MACH_7780SE		0
#endif
#ifdef CONFIG_SH_7751_SYSTEMH
  #define MACH_7751SYSTEMH		1
#else
  #define MACH_7751SYSTEMH		0
#endif
#ifdef CONFIG_SH_HP6XX
  #define MACH_HP6XX		1
#else
  #define MACH_HP6XX		0
#endif
#ifdef CONFIG_SH_DREAMCAST
  #define MACH_DREAMCAST		1
#else
  #define MACH_DREAMCAST		0
#endif
#ifdef CONFIG_SH_SECUREEDGE5410
  #define MACH_SNAPGEAR		1
#else
  #define MACH_SNAPGEAR		0
#endif
#ifdef CONFIG_SH_EDOSK7705
  #define MACH_EDOSK7705		1
#else
  #define MACH_EDOSK7705		0
#endif
#ifdef CONFIG_SH_EDOSK7760
  #define MACH_EDOSK7760		1
#else
  #define MACH_EDOSK7760		0
#endif
#ifdef CONFIG_SH_SH4202_MICRODEV
  #define MACH_SH4202_MICRODEV		1
#else
  #define MACH_SH4202_MICRODEV		0
#endif
#ifdef CONFIG_SH_SH03
  #define MACH_SH03		1
#else
  #define MACH_SH03		0
#endif
#ifdef CONFIG_SH_LANDISK
  #define MACH_LANDISK		1
#else
  #define MACH_LANDISK		0
#endif
#ifdef CONFIG_SH_R7780RP
  #define MACH_R7780RP		1
#else
  #define MACH_R7780RP		0
#endif
#ifdef CONFIG_SH_R7780MP
  #define MACH_R7780MP		1
#else
  #define MACH_R7780MP		0
#endif
#ifdef CONFIG_SH_R7785RP
  #define MACH_R7785RP		1
#else
  #define MACH_R7785RP		0
#endif
#ifdef CONFIG_SH_TITAN
  #define MACH_TITAN		1
#else
  #define MACH_TITAN		0
#endif
#ifdef CONFIG_SH_SHMIN
  #define MACH_SHMIN		1
#else
  #define MACH_SHMIN		0
#endif
#ifdef CONFIG_SH_LBOX_RE2
  #define MACH_LBOXRE2		1
#else
  #define MACH_LBOXRE2		0
#endif
#ifdef CONFIG_SH_X3PROTO
  #define MACH_X3PROTO		1
#else
  #define MACH_X3PROTO		0
#endif
#ifdef CONFIG_SH_MAGIC_PANEL_R2
  #define MACH_MAGICPANELR2		1
#else
  #define MACH_MAGICPANELR2		0
#endif
#ifdef CONFIG_RTS7751R2D_PLUS
  #define MACH_R2D_PLUS		1
#else
  #define MACH_R2D_PLUS		0
#endif
#ifdef CONFIG_RTS7751R2D_1
  #define MACH_R2D_1		1
#else
  #define MACH_R2D_1		0
#endif
#ifdef CONFIG_SH_CAYMAN
  #define MACH_CAYMAN		1
#else
  #define MACH_CAYMAN		0
#endif
#ifdef CONFIG_SH_SDK7780
  #define MACH_SDK7780		1
#else
  #define MACH_SDK7780		0
#endif
#ifdef CONFIG_SH_MIGOR
  #define MACH_MIGOR		1
#else
  #define MACH_MIGOR		0
#endif
#ifdef CONFIG_SH_RSK7201
  #define MACH_RSK7201		1
#else
  #define MACH_RSK7201		0
#endif
#ifdef CONFIG_SH_RSK7203
  #define MACH_RSK7203		1
#else
  #define MACH_RSK7203		0
#endif
#ifdef CONFIG_SH_AP325RXA
  #define MACH_AP325RXA		1
#else
  #define MACH_AP325RXA		0
#endif
#ifdef CONFIG_SH_SH7763RDP
  #define MACH_SH7763RDP		1
#else
  #define MACH_SH7763RDP		0
#endif
#ifdef CONFIG_SH_SH7785LCR
  #define MACH_SH7785LCR		1
#else
  #define MACH_SH7785LCR		0
#endif
#ifdef CONFIG_SH_SH7785LCR_PT
  #define MACH_SH7785LCR_PT		1
#else
  #define MACH_SH7785LCR_PT		0
#endif
#ifdef CONFIG_SH_URQUELL
  #define MACH_URQUELL		1
#else
  #define MACH_URQUELL		0
#endif
#ifdef CONFIG_SH_ESPT
  #define MACH_ESPT		1
#else
  #define MACH_ESPT		0
#endif
#ifdef CONFIG_SH_POLARIS
  #define MACH_POLARIS		1
#else
  #define MACH_POLARIS		0
#endif
#ifdef CONFIG_SH_KFR2R09
  #define MACH_KFR2R09		1
#else
  #define MACH_KFR2R09		0
#endif
#ifdef CONFIG_SH_ECOVEC
  #define MACH_ECOVEC		1
#else
  #define MACH_ECOVEC		0
#endif

/* Machtype checks */
#define mach_is_se()			(MACH_SE)
#define mach_is_highlander()			(MACH_HIGHLANDER)
#define mach_is_rts7751r2d()			(MACH_RTS7751R2D)
#define mach_is_rsk()			(MACH_RSK)
#define mach_is_hd64461()			(MACH_HD64461)
#define mach_is_7206se()			(MACH_7206SE)
#define mach_is_7343se()			(MACH_7343SE)
#define mach_is_7619se()			(MACH_7619SE)
#define mach_is_7721se()			(MACH_7721SE)
#define mach_is_7722se()			(MACH_7722SE)
#define mach_is_7724se()			(MACH_7724SE)
#define mach_is_7751se()			(MACH_7751SE)
#define mach_is_7780se()			(MACH_7780SE)
#define mach_is_7751systemh()			(MACH_7751SYSTEMH)
#define mach_is_hp6xx()			(MACH_HP6XX)
#define mach_is_dreamcast()			(MACH_DREAMCAST)
#define mach_is_snapgear()			(MACH_SNAPGEAR)
#define mach_is_edosk7705()			(MACH_EDOSK7705)
#define mach_is_edosk7760()			(MACH_EDOSK7760)
#define mach_is_sh4202_microdev()			(MACH_SH4202_MICRODEV)
#define mach_is_sh03()			(MACH_SH03)
#define mach_is_landisk()			(MACH_LANDISK)
#define mach_is_r7780rp()			(MACH_R7780RP)
#define mach_is_r7780mp()			(MACH_R7780MP)
#define mach_is_r7785rp()			(MACH_R7785RP)
#define mach_is_titan()			(MACH_TITAN)
#define mach_is_shmin()			(MACH_SHMIN)
#define mach_is_lboxre2()			(MACH_LBOXRE2)
#define mach_is_x3proto()			(MACH_X3PROTO)
#define mach_is_magicpanelr2()			(MACH_MAGICPANELR2)
#define mach_is_r2d_plus()			(MACH_R2D_PLUS)
#define mach_is_r2d_1()			(MACH_R2D_1)
#define mach_is_cayman()			(MACH_CAYMAN)
#define mach_is_sdk7780()			(MACH_SDK7780)
#define mach_is_migor()			(MACH_MIGOR)
#define mach_is_rsk7201()			(MACH_RSK7201)
#define mach_is_rsk7203()			(MACH_RSK7203)
#define mach_is_ap325rxa()			(MACH_AP325RXA)
#define mach_is_sh7763rdp()			(MACH_SH7763RDP)
#define mach_is_sh7785lcr()			(MACH_SH7785LCR)
#define mach_is_sh7785lcr_pt()			(MACH_SH7785LCR_PT)
#define mach_is_urquell()			(MACH_URQUELL)
#define mach_is_espt()			(MACH_ESPT)
#define mach_is_polaris()			(MACH_POLARIS)
#define mach_is_kfr2r09()			(MACH_KFR2R09)
#define mach_is_ecovec()			(MACH_ECOVEC)

#endif /* __ASM_SH_MACHTYPES_H */
