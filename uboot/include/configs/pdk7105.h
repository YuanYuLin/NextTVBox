/*
 * (C) Copyright 2008-2009 STMicroelectronics.
 *
 * Sean McGoogan <Sean.McGoogan@st.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_SH4	1		/* This is an SH4 CPU		*/
#define CONFIG_CPU_SUBTYPE_SH4_3XX	/* it is an SH4-300		*/


/*-----------------------------------------------------------------------
 *	Jumper settings to select between the SoC's 3 boot-modes:
 *		a) boot from NOR flash
 *		b) boot from NAND flash
 *		c) boot from SPI serial flash
 *
 *	With the LED display panel facing the user:
 *
 *	Jumper	Location	NOR	NAND	SPI
 *	------	--------	---	----	---
 *	JE6	top-most	EAST	EAST	WEST
 *	JE5	below JE6	EAST	WEST	EAST
 *	JE3	left-side	NORTH	SOUTH	SOUTH
 *	JE2	right-side	SOUTH	NORTH	NORTH
 */


/*-----------------------------------------------------------------------
 * Are we booting directly from a NAND Flash device ?
 * If so, then define the "CFG_BOOT_FROM_NAND" macro,
 * otherwise (e.g. NOR/SPI Flash booting), do not define it.
 */
#undef CFG_BOOT_FROM_NAND		/* define to build a NAND-bootable image */


/*-----------------------------------------------------------------------
 * Are we booting directly from a SPI Serial Flash device ?
 * If so, then define the "CFG_BOOT_FROM_SPI" macro,
 * otherwise (e.g. for NOR/NAND Flash booting), do not define it.
 */
#undef CFG_BOOT_FROM_SPI		/* define to build a SPI-bootable image */
#define  CFG_BOOT_FROM_SPI


/*-----------------------------------------------------------------------
 * Start addresses for the final memory configuration
 * Assume we run out of uncached memory for the moment
 */
#define CFG_NAND_YAFFS_WRITE 

#if defined(CFG_BOOT_FROM_SPI)		/* we are booting from SPI, so *DO* swap CSA and CSC with JE2 */
#define CFG_EMI_SPI_BASE	0xA0000000	/* CSA: SPI Flash,  Physical 0x00000000 (64MiB) */
#define CFG_EMI_NOR_BASE	0xA4000000	/* CSB: NOR Flash,  Physical 0x04000000 (32MiB) */
#define CFG_EMI_NAND_BASE	0xA6000000	/* CSC: NAND Flash, Physical 0x06000000 (8MiB) */
#define CFG_NAND_FLEX_CSn_MAP	{ 0 }		/* NAND is on Chip Select CSA */
#elif defined(CFG_BOOT_FROM_NAND)	/* we are booting from NAND, so *DO* swap CSA and CSC with JE2 */
#define CFG_EMI_NAND_BASE	0xA0000000	/* CSA: NAND Flash, Physical 0x00000000 (64MiB) */
#define CFG_EMI_NOR_BASE	0xA4000000	/* CSB: NOR Flash,  Physical 0x04000000 (32MiB) */
#define CFG_NAND_FLEX_CSn_MAP	{ 0 }		/* NAND is on Chip Select CSA */
#else					/* else, do *NOT* swap CSA and CSC using JE2 */
#define CFG_EMI_NOR_BASE	0xA0000000	/* CSA: NOR Flash,  Physical 0x00000000 (64MiB) */
#define CFG_EMI_NAND_BASE	0xA6000000	/* CSC: NAND Flash, Physical 0x06000000 (8MiB) */
#define CFG_NAND_FLEX_CSn_MAP	{ 2 }		/* NAND is on Chip Select CSC */
#endif /* CFG_BOOT_FROM_NAND */

#ifdef CONFIG_SH_SE_MODE
#define CFG_FLASH_BASE		CFG_EMI_NOR_BASE/* NOR FLASH (uncached) via PMB */
#define CFG_SE_PHYSICAL_BASE	0x40000000	/* LMI Physical Address */
#define CFG_SDRAM_BASE		0x80000000      /* LMI    Cached addr via PMB */
#define CFG_SE_UNACHED_BASE	0x90000000	/* LMI UN-cached addr via PMB */
#define CFG_SE_SDRAM_WINDOW	(CFG_SDRAM_SIZE-1)
#else
#define CFG_FLASH_BASE		CFG_EMI_NOR_BASE/* NOR FLASH in P2 region */
#define CFG_SDRAM_BASE		0x8C000000      /* SDRAM in P1 region */
#endif

#define CFG_SDRAM_SIZE		0x10000000	/* 256 MiB of LMI SDRAM */

#define CFG_MONITOR_LEN		0x00040000	/* Reserve 256 KiB for Monitor */
#define CFG_MONITOR_BASE        CFG_FLASH_BASE
#define CFG_MALLOC_LEN		(1 << 20)	/* Reserve 1 MiB for malloc */
#define CFG_BOOTPARAMS_LEN	(128 << 10)	/* 128 KiB */
#define CFG_GBL_DATA_SIZE	1024		/* Global data structures */

#define CFG_MEMTEST_START	CFG_SDRAM_BASE
#define CFG_MEMTEST_END		(CFG_SDRAM_BASE + CFG_SDRAM_SIZE - (3 << 20))

#define CONFIG_BAUDRATE		115200
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define XSTR(s) STR(s)
#define STR(s) #s

#define BOARD pdk7105

#if CFG_MONITOR_LEN == 0x00020000		/* 128 KiB */
#	define MONITOR_SECTORS	"1:0"		/* 1 sector */
#elif CFG_MONITOR_LEN == 0x00040000		/* 256 KiB */
#	define MONITOR_SECTORS	"1:0-1"		/* 2 sectors */
#else						/* unknown */
#	error "Unable to determine sectors for monitor"
#endif

#define CONFIG_EXTRA_ENV_SETTINGS \
		"board=" XSTR(BOARD) "\0" \
		"monitor_base=" XSTR(CFG_MONITOR_BASE) "\0" \
		"monitor_len=" XSTR(CFG_MONITOR_LEN) "\0" \
		"monitor_sec=" MONITOR_SECTORS "\0" \
		"load_addr=" XSTR(CFG_LOAD_ADDR) "\0" \
		"ipaddr=192.9.150.61\0" \
		"serverip=192.9.150.67\0" \
		"bootdelay=0\0" \
	"update_uboot=" \
               "usb start;" \
		  "fatload usb 0 80000000 u-boot.bin;" \
                 "update_spi_uboot \0" \
	"unprot=" \
		"protect off $monitor_sec\0" \
		"update=" \
		  "erase $monitor_sec;" \
		  "cp.b $load_addr $monitor_base $monitor_len;" \
		  "protect on $monitor_sec\0" \
		  "ethaddr=12:34:56:78:06:BD\0"\
		  "bootcmd=nboot 80000000  0  100000;bootm 80000000\0"\
		  "bootargs= console=ttyAS0,115200 root=/dev/mtdblock1 rootfstype=yaffs2 rw nwhwconf=device:eth0,hwaddr:10:08:E2:12:06:BD phyaddr:0,watchdog:5000 mem=120M bigphysarea=2048\0"

//		  "bootargs= console=ttyAS0,115200 root=/dev/mtdblock1 rootfstype=jffs2 rw nwhwconf=device:eth0,hwaddr:10:08:E2:12:06:BD phyaddr:0,watchdog:5000 ip=192.168.111.111::192.168.10.1:255.255.255.0:7105_1::off mem=120M bigphysarea=2048\0"
/*--------------------------------------------------------------
 * Command line configuration.
 */

#include <config_cmd_default.h>

#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_NFS
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII

/*--------------------------------------------------------------
 * Serial console info
 */

/*
 * We can use one of two methods for the "serial" console.
 * We can either use the (normal hardware) internal ST ASC UART;
 * OR we can use STMicroelectronics' DTF (Data Transfer Format)
 * mechanism over a JTAG link to a remote GDB debugger.
 */
#if 1
#	define CONFIG_STM_ASC_SERIAL	/* use a ST ASC UART */
#else
#	define CONFIG_STM_DTF_SERIAL	/* use DTF over JTAG */
#endif

/* choose which ST ASC UART to use */
#if 1
	/* 9-pin D-type connector on STi7105-SDK-SB daughter board */
#	define CFG_STM_ASC_BASE		ST40_ASC2_REGS_BASE	/* UART #2 */
#else
	/* JN5, 6-way connector - QQQ NOT TESTED */
#	define CFG_STM_ASC_BASE		ST40_ASC3_REGS_BASE	/* UART #3 */
#endif

/*---------------------------------------------------------------
 * Ethernet driver config
 */

/*
 * There are 2 options for ethernet, both use the on-chip ST-GMAC.
 * The choice in PHYs are:
 *    The on-board Micrel KSZ8041FTL
 *    External PHY connected via the MII off-board 15x2 header.
 */

/* are we using the internal ST GMAC device ? */
#define CONFIG_DRIVER_NET_STM_GMAC

/*
 * Select the appropriate base address for the GMAC.
 * Also, choose which PHY to use.
 */
#ifdef CONFIG_DRIVER_NET_STM_GMAC
#	define CFG_STM_STMAC_BASE	0xfd110000ul	/* MAC = STM GMAC0 */
//#	define CONFIG_STMAC_KSZ8041FTL			/* PHY = Micrel KSZ8041FTL */
#     define CONFIG_CMD_MII
#     define CONFIG_ETHADDR  DE:EA:FF:FF:01:01
#     define CONFIG_STMAC_STE10XP  

#else
#	undef CONFIG_CMD_NET		/* undefine if no networking at all */
#endif	/* CONFIG_DRIVER_NET_STM_GMAC */

/*  If this board does not have eeprom for ethernet address so allow the user
 *  to set it in the environment
 */
#define CONFIG_ENV_OVERWRITE


/*---------------------------------------------------------------
 * USB driver config
 */

/* Choose if we want USB Mass-Storage Support */
#define CONFIG_SH_STB7100_USB

#ifdef CONFIG_SH_STB7100_USB
#	define CONFIG_CMD_USB
#	define CONFIG_CMD_FAT
#	define CONFIG_USB_OHCI_NEW
#	define CONFIG_USB_STORAGE
#	define CFG_USB_OHCI_CPU_INIT
#	define CFG_USB0_BASE			0xfe100000	/* rear (adjacent to RJ-45) */
#	define CFG_USB1_BASE			0xfea00000	/* front (near corner) */
#	define CFG_USB_BASE			CFG_USB0_BASE
//#	define CFG_USB_BASE			CFG_USB1_BASE
#	define CONFIG_SH_STX_STX7105_USB_PORT0		/* enable Port #0 */
//#	define CONFIG_SH_STX_STX7105_USB_PORT1		/* enable Port #1 */
#	define CONFIG_SH_STX_STX7105_USB_OC	1	/* use overcurrent */
#	define CONFIG_SH_STX_STX7105_USB_PW	1	/* use power control */
#	define CFG_USB_OHCI_REGS_BASE		(CFG_USB_BASE+0xffc00)

/* JGONG 0427 MASK
#   define USB_EXT_REGS		(CFG_USB0_BASE+0xffc00)
#   define USB_INT_REGS		(CFG_USB1_BASE+0xffc00)
*/

#   define USB_EXT_REGS		(CFG_USB1_BASE+0xffc00)
#   define USB_INT_REGS		(CFG_USB0_BASE+0xffc00)


#	define CFG_USB_OHCI_SLOT_NAME		"ohci"
#	define CFG_USB_OHCI_MAX_ROOT_PORTS	1
#	define LITTLEENDIAN
#endif	/* ifdef CONFIG_SH_STB7100_USB */

/*---------------------------------------------------------------
 * SATA driver config
 */

/* SATA works on cut 3.x of the STx7105 (just one port) */
/* Choose if we want to use a SATA HDD */
//#define CONFIG_SH_STM_SATA

#ifdef CONFIG_SH_STM_SATA
#	define CONFIG_CMD_IDE				/* enable "ide" command set */
#	define CFG_ATA_BASE_ADDR	0xfe209000	/* E-SATA connector */
#	define CFG_ATA_IDE0_OFFSET	0x800		/* Host Controller */
#	define CFG_ATA_REG_OFFSET	0x0
#	define CFG_ATA_DATA_OFFSET	0x0
#	define CFG_ATA_STRIDE		0x4
#	define CFG_IDE_MAXBUS		1
#	define CFG_IDE_MAXDEVICE	1
#endif	/* CONFIG_SH_STM_SATA */

#if defined(CONFIG_SH_STM_SATA) ||	\
    defined(CONFIG_SH_STB7100_USB)
#	define CFG_64BIT_LBA
#	define CONFIG_LBA48
#	define CONFIG_DOS_PARTITION
#	define CONFIG_CMD_EXT2
#endif

/*-----------------------------------------------------------------------
 * Miscellaneous configurable options
 */

#define CFG_HUSH_PARSER		1
#define CONFIG_AUTO_COMPLETE	1
#define CFG_LONGHELP		1		/* undef to save memory		*/
#define CFG_PROMPT		"PDK7105> "	/* Monitor Command Prompt	*/
#define CFG_PROMPT_HUSH_PS2	"> "
#define CFG_CBSIZE		1024
#define CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size	*/
#define CFG_MAXARGS		16		/* max number of command args	*/
#define CFG_HZ			1000		/* HZ for timer ticks	*/
#define CFG_LOAD_ADDR		CFG_SDRAM_BASE	/* default load address		*/
#define CFG_BOOTMAPSZ		CFG_SDRAM_SIZE  //(16 << 20)	/* initial linux memory size	*/
#define CONFIG_BOOTDELAY	0		/* default delay before executing bootcmd */
#define CONFIG_ZERO_BOOTDELAY_CHECK

#define CONFIG_CMDLINE_EDITING

/*-----------------------------------------------------------------------
 * FLASH organization
 */

/* Choose if we want FLASH Support (SPI, NAND &/or NOR devices)
 * With the PDK7105 combination, we may use *both*
 * NOR and NAND flash, at the same time, if we want.
 *
 * Note: by default CONFIG_CMD_FLASH is defined in config_cmd_default.h
 */
#undef CONFIG_CMD_FLASH		/* undefine it, define only if needed */
//#define CONFIG_CMD_FLASH	/* define for NOR flash */
#define CONFIG_CMD_NAND		/* define for NAND flash */
#define CONFIG_SPI_FLASH	/* define for SPI serial flash */

/*-----------------------------------------------------------------------
 * NOR FLASH organization
 */

/* S29GL01GP: 128MiB, 1024 blocks * 128KiB block size */
#ifdef CONFIG_CMD_FLASH				/* NOR flash present ? */
#	define CFG_FLASH_CFI_DRIVER
#	define CFG_FLASH_CFI
#	define CONFIG_FLASH_PROTECT_SINGLE_CELL
#	define CFG_FLASH_PROTECTION	1	/* use hardware flash protection	*/
#	define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks		*/
#	define CFG_MAX_FLASH_SECT	1024	/* max number of sectors on one chip	*/
#	define CFG_FLASH_EMPTY_INFO		/* test if each sector is empty		*/
#	define MTDPARTS_NOR						\
	"physmap-flash:"	/* First NOR flash device */		\
		"256k(U-Boot)"		/* first partition */		\
		",128k(Environment)"					\
		",4M(Kernel)"						\
		",-(RestOfNor0)"	/* last partition */
#	define MTDIDS_NOR						\
	"nor0=physmap-flash"	/* First NOR flash device */
#else
#	undef CONFIG_CMD_IMLS			/* NOR-flash specific */
#	define CFG_NO_FLASH			/* NOR-flash specific */
#endif	/* CONFIG_CMD_FLASH */

/*-----------------------------------------------------------------------
 * NAND FLASH organization
 */

/* HY27UH08AG5B : 2GiB  8-bit, 16384 Blocks (128KiB+4KiB) of 64 Pages (2048+64) */
#ifdef CONFIG_CMD_NAND				/* NAND flash present ? */
#	define CFG_MAX_NAND_DEVICE	1
#	define NAND_MAX_CHIPS		CFG_MAX_NAND_DEVICE
#	define CFG_NAND0_BASE		CFG_EMI_NAND_BASE
#	define CFG_NAND_BASE_LIST	{ CFG_NAND0_BASE }
#	define MTDPARTS_NAND						\
	"gen_nand.1:"		/* First NAND flash device */		\
		"128k(env-nand0)"	/* first partition */		\
		",4M(kernel-nand0)"					\
		",32M(root-nand0)"					\
		",-(RestOfNand0)"	/* last partition */
#	define MTDIDS_NAND						\
	"nand0=gen_nand.1"	/* First NAND flash device */

	/*
	 * Currently, there are 2 main modes to read/write from/to
	 * NAND devices on STM SoCs:
	 *	a) "bit-banging" (can NOT be used in boot-from-NAND)
	 *	b) FLEX-mode (only supported means for boot-from-NAND)
	 * If CFG_NAND_FLEX_MODE is defined, then FLEX-mode will be
	 * used, otherwise, "bit-banging" will be used.
	 */
#	define CFG_NAND_FLEX_MODE	/* define to use NAND FLEX-MODE */

	/*
	 * Do we want to read/write NAND Flash compatible with the ST40's
	 * NAND Controller H/W IP block for "boot-mode"? If we want
	 * to read/write NAND flash that is meant to support booting
	 * from NAND, then we need to use 3 bytes of ECC per 128 byte
	 * record.  If so, then define the "CFG_NAND_ECC_HW3_128" macro.
	 */
#	define CFG_NAND_ECC_HW3_128	/* define for "boot-from-NAND" compatibility */

	/*
	 * If using CFG_NAND_ECC_HW3_128, then we must also define
	 * where the (high watermark) boundary is. That is, the
	 * NAND offset, below which we are in "boot-mode", and
	 * must use 3 bytes of ECC for each 128 byte record.
	 * For this offset (and above) we can use any supported
	 * ECC configuration (e.g 3/256 S/W, or 3/512 H/W).
	 */
#	define CFG_NAND_STM_BOOT_MODE_BOUNDARY (1ul << 20)	/* 1 MiB */

	/*
	 * If we want to store the U-boot environment variables in
	 * the NAND device, then we also need to specify *where* the
	 * environment variables will be stored. Typically this
	 * would be immediately after the U-boot monitor itself.
	 * However, that *may* be a bad block. Define the following
	 * to place the environment in an appropriate good block.
	 */
#	define CFG_NAND_ENV_OFFSET (CFG_MONITOR_LEN + 0x0)	/* immediately after u-boot.bin */
#endif	/* CONFIG_CMD_NAND */

/*-----------------------------------------------------------------------
 * SPI SERIAL FLASH organization
 */

/*
 *	Name	Manuf	Device
 *	-----	-----	------
 *	US3	ST	M25P64
 */
#if defined(CONFIG_SPI_FLASH)			/* SPI serial flash present ? */
#	define CONFIG_SPI_FLASH_ST		/* ST M25Pxx (US3) */
#	define CONFIG_SPI			/* enable the SPI driver */
#	define CONFIG_CMD_SPI			/* SPI serial bus command support */
#	define CONFIG_CMD_EEPROM		/* enable the "eeprom" command set */
#	define CFG_I2C_FRAM			/* to minimize performance degradation */
#	undef  CFG_EEPROM_PAGE_WRITE_DELAY_MS	/* to minimize performance degradation */
#	define CONFIG_SOFT_SPI			/* Use "bit-banging" PIO (not the SSC) */
#endif	/* CONFIG_SPI_FLASH */

#if defined(CONFIG_SOFT_SPI)			/* Use "bit-banging" for SPI */
#	define SPI_SCL(val)	do { stx7105_spi_scl((val)); } while (0)
#	define SPI_SDA(val)	do { stx7105_spi_sda((val)); } while (0)
#	define SPI_DELAY	do { udelay(1); } while (0)	/* QQQ: only 500 kHz ??? */
#	define SPI_READ		stx7105_spi_read()
#endif	/* CONFIG_SOFT_SPI */


/*-----------------------------------------------------------------------
 * Address, size, & location of U-boot's Environment Sector
 */

#define CFG_ENV_SIZE			0x10000  /* 16 KiB of environment data */

#if 1 && defined(CONFIG_CMD_FLASH)		/* NOR flash present ? */
#	define CFG_ENV_IS_IN_FLASH		/* environment in NOR flash */
#	define CFG_ENV_OFFSET	CFG_MONITOR_LEN	/* immediately after u-boot.bin */
#	define CFG_ENV_SECT_SIZE	0x20000	/* 128 KiB Sector size */
#elif 0 && defined(CONFIG_CMD_NAND)		/* NAND flash present ? */
#	define CFG_ENV_IS_IN_NAND		/* environment in NAND flash */
#	define CFG_ENV_OFFSET	CFG_NAND_ENV_OFFSET
#	if CFG_ENV_SIZE < 0x20000		/* needs to be a multiple of block-size */
#		undef CFG_ENV_SIZE		/* give it just one large-page block */
#		define CFG_ENV_SIZE	0x20000	/* 128 KiB of environment data */
#	endif /* if CFG_ENV_SIZE < 0x20000 */
#elif 1 && defined(CONFIG_SPI_FLASH)		/* SPI serial flash present ? */
#	define CFG_ENV_IS_IN_EEPROM		/* ENV is stored in SPI Serial Flash */
#	define CFG_ENV_OFFSET	      0x80000             //CFG_MONITOR_LEN	/* immediately after u-boot.bin */
#else
#	define CFG_ENV_IS_NOWHERE		/* ENV is stored in volatile RAM */
#endif	/* CONFIG_CMD_NAND */

/*----------------------------------------------------------------------
 * JFFS2 + MTD Partition support
 */

#if 1 && (defined(CONFIG_CMD_FLASH) || defined(CONFIG_CMD_NAND))
#	define CONFIG_CMD_JFFS2			/* enable JFFS2 support */

#define CONFIG_JFFS2_DEV		"nand0"
#define CONFIG_JFFS2_PART_SIZE		0x6400000
#define CONFIG_JFFS2_PART_OFFSET	0x9b00000
#define CONFIG_JFFS2_LZO_LZARI
#endif

#if defined(CONFIG_CMD_JFFS2)
//#	define CONFIG_JFFS2_CMDLINE		/* mtdparts command line support */
#undef  CONFIG_JFFS2_CMDLINE		/* mtdparts command line support */
#	define CONFIG_JFFS2_NAND	 1	/* JFFS2 support on NAND Flash */
#	if defined(CONFIG_CMD_FLASH) && defined(CONFIG_CMD_NAND) /* Both NOR + NAND */
#		define MTDPARTS_DEFAULT						\
		"mtdparts="							\
			MTDPARTS_NOR	/* NOR flash devices */			\
			";"		/* delimiter */				\
			MTDPARTS_NAND	/* NAND flash devices */
#		define MTDIDS_DEFAULT						\
			MTDIDS_NOR	/* NOR flash devices */			\
			","		/* delimiter */				\
			MTDIDS_NAND	/* NAND flash devices */
#	elif defined(CONFIG_CMD_FLASH)		/* Only NOR flash devices */
#		define MTDPARTS_DEFAULT	"mtdparts=" MTDPARTS_NOR
#		define MTDIDS_DEFAULT	MTDIDS_NOR
#	elif defined(CONFIG_CMD_NAND)		/* Only NAND flash devices */
#		define MTDPARTS_DEFAULT	"mtdparts=" MTDPARTS_NAND
#		define MTDIDS_DEFAULT	MTDIDS_NAND
#	endif	/* defined(CONFIG_CMD_FLASH) && defined(CONFIG_CMD_NAND) */
#endif	/* CONFIG_CMD_JFFS2 */

#endif	/* __CONFIG_H */
