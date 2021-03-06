/*
 * Broadcom Starfighter 2 switch register defines
 *
 * Copyright (C) 2014, Broadcom Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef __BCM_SF2_REGS_H
#define __BCM_SF2_REGS_H

/* Register set relative to 'REG' */
#define REG_SWITCH_CNTRL		0x00
#define  MDIO_MASTER_SEL		(1 << 0)

#define REG_SWITCH_STATUS		0x04
#define REG_DIR_DATA_WRITE		0x08
#define REG_DIR_DATA_READ		0x0C

#define REG_SWITCH_REVISION		0x18
#define  SF2_REV_MASK			0xffff
#define  SWITCH_TOP_REV_SHIFT		16
#define  SWITCH_TOP_REV_MASK		0xffff

#define REG_PHY_REVISION		0x1C
#define  PHY_REVISION_MASK		0xffff

#define REG_SPHY_CNTRL			0x2C
#define  IDDQ_BIAS			(1 << 0)
#define  EXT_PWR_DOWN			(1 << 1)
#define  FORCE_DLL_EN			(1 << 2)
#define  IDDQ_GLOBAL_PWR		(1 << 3)
#define  CK25_DIS			(1 << 4)
#define  PHY_RESET			(1 << 5)
#define  PHY_PHYAD_SHIFT		8
#define  PHY_PHYAD_MASK			0x1F

#define REG_RGMII_0_BASE		0x34
#define REG_RGMII_CNTRL			0x00
#define REG_RGMII_IB_STATUS		0x04
#define REG_RGMII_RX_CLOCK_DELAY_CNTRL	0x08
#define REG_RGMII_CNTRL_SIZE		0x0C
#define REG_RGMII_CNTRL_P(x)		(REG_RGMII_0_BASE + \
					((x) * REG_RGMII_CNTRL_SIZE))
/* Relative to REG_RGMII_CNTRL */
#define  RGMII_MODE_EN			(1 << 0)
#define  ID_MODE_DIS			(1 << 1)
#define  PORT_MODE_SHIFT		2
#define  INT_EPHY			(0 << PORT_MODE_SHIFT)
#define  INT_GPHY			(1 << PORT_MODE_SHIFT)
#define  EXT_EPHY			(2 << PORT_MODE_SHIFT)
#define  EXT_GPHY			(3 << PORT_MODE_SHIFT)
#define  EXT_REVMII			(4 << PORT_MODE_SHIFT)
#define  PORT_MODE_MASK			0x7
#define  RVMII_REF_SEL			(1 << 5)
#define  RX_PAUSE_EN			(1 << 6)
#define  TX_PAUSE_EN			(1 << 7)
#define  TX_CLK_STOP_EN			(1 << 8)
#define  LPI_COUNT_SHIFT		9
#define  LPI_COUNT_MASK			0x3F

#define REG_LED_CNTRL_BASE		0x90
#define REG_LED_CNTRL(x)		(REG_LED_CNTRL_BASE + (x) * 4)
#define  SPDLNK_SRC_SEL			(1 << 24)

/* Register set relative to 'INTRL2_0' and 'INTRL2_1' */
#define INTRL2_CPU_STATUS		0x00
#define INTRL2_CPU_SET			0x04
#define INTRL2_CPU_CLEAR		0x08
#define INTRL2_CPU_MASK_STATUS		0x0c
#define INTRL2_CPU_MASK_SET		0x10
#define INTRL2_CPU_MASK_CLEAR		0x14

/* Shared INTRL2_0 and INTRL2_ interrupt sources macros */
#define P_LINK_UP_IRQ(x)		(1 << (0 + (x)))
#define P_LINK_DOWN_IRQ(x)		(1 << (1 + (x)))
#define P_ENERGY_ON_IRQ(x)		(1 << (2 + (x)))
#define P_ENERGY_OFF_IRQ(x)		(1 << (3 + (x)))
#define P_GPHY_IRQ(x)			(1 << (4 + (x)))
#define P_NUM_IRQ			5
#define P_IRQ_MASK(x)			(P_LINK_UP_IRQ((x)) | \
					 P_LINK_DOWN_IRQ((x)) | \
					 P_ENERGY_ON_IRQ((x)) | \
					 P_ENERGY_OFF_IRQ((x)) | \
					 P_GPHY_IRQ((x)))

/* INTRL2_0 interrupt sources */
#define P0_IRQ_OFF			0
#define MEM_DOUBLE_IRQ			(1 << 5)
#define EEE_LPI_IRQ			(1 << 6)
#define P5_CPU_WAKE_IRQ			(1 << 7)
#define P8_CPU_WAKE_IRQ			(1 << 8)
#define P7_CPU_WAKE_IRQ			(1 << 9)
#define IEEE1588_IRQ			(1 << 10)
#define MDIO_ERR_IRQ			(1 << 11)
#define MDIO_DONE_IRQ			(1 << 12)
#define GISB_ERR_IRQ			(1 << 13)
#define UBUS_ERR_IRQ			(1 << 14)
#define FAILOVER_ON_IRQ			(1 << 15)
#define FAILOVER_OFF_IRQ		(1 << 16)
#define TCAM_SOFT_ERR_IRQ		(1 << 17)

/* INTRL2_1 interrupt sources */
#define P7_IRQ_OFF			0
#define P_IRQ_OFF(x)			((6 - (x)) * P_NUM_IRQ)

/* Register set relative to 'CORE' */
#define CORE_G_PCTL_PORT0		0x00000
#define CORE_G_PCTL_PORT(x)		(CORE_G_PCTL_PORT0 + (x * 0x4))
#define CORE_IMP_CTL			0x00020
#define  RX_DIS				(1 << 0)
#define  TX_DIS				(1 << 1)
#define  RX_BCST_EN			(1 << 2)
#define  RX_MCST_EN			(1 << 3)
#define  RX_UCST_EN			(1 << 4)
#define  G_MISTP_STATE_SHIFT		5
#define  G_MISTP_NO_STP			(0 << G_MISTP_STATE_SHIFT)
#define  G_MISTP_DIS_STATE		(1 << G_MISTP_STATE_SHIFT)
#define  G_MISTP_BLOCK_STATE		(2 << G_MISTP_STATE_SHIFT)
#define  G_MISTP_LISTEN_STATE		(3 << G_MISTP_STATE_SHIFT)
#define  G_MISTP_LEARN_STATE		(4 << G_MISTP_STATE_SHIFT)
#define  G_MISTP_FWD_STATE		(5 << G_MISTP_STATE_SHIFT)
#define  G_MISTP_STATE_MASK		0x7

#define CORE_SWMODE			0x0002c
#define  SW_FWDG_MODE			(1 << 0)
#define  SW_FWDG_EN			(1 << 1)
#define  RTRY_LMT_DIS			(1 << 2)

#define CORE_STS_OVERRIDE_IMP		0x00038
#define  GMII_SPEED_UP_2G		(1 << 6)
#define  MII_SW_OR			(1 << 7)

#define CORE_NEW_CTRL			0x00084
#define  IP_MC				(1 << 0)
#define  OUTRANGEERR_DISCARD		(1 << 1)
#define  INRANGEERR_DISCARD		(1 << 2)
#define  CABLE_DIAG_LEN			(1 << 3)
#define  OVERRIDE_AUTO_PD_WAR		(1 << 4)
#define  EN_AUTO_PD_WAR			(1 << 5)
#define  UC_FWD_EN			(1 << 6)
#define  MC_FWD_EN			(1 << 7)

#define CORE_SWITCH_CTRL		0x00088
#define  MII_DUMB_FWDG_EN		(1 << 6)

#define CORE_SFT_LRN_CTRL		0x000f8
#define  SW_LEARN_CNTL(x)		(1 << (x))

#define CORE_STS_OVERRIDE_GMIIP_PORT(x)	(0x160 + (x) * 4)
#define  LINK_STS			(1 << 0)
#define  DUPLX_MODE			(1 << 1)
#define  SPEED_SHIFT			2
#define  SPEED_MASK			0x3
#define  RXFLOW_CNTL			(1 << 4)
#define  TXFLOW_CNTL			(1 << 5)
#define  SW_OVERRIDE			(1 << 6)

#define CORE_WATCHDOG_CTRL		0x001e4
#define  SOFTWARE_RESET			(1 << 7)
#define  EN_CHIP_RST			(1 << 6)
#define  EN_SW_RESET			(1 << 4)

#define CORE_FAST_AGE_CTRL		0x00220
#define  EN_FAST_AGE_STATIC		(1 << 0)
#define  EN_AGE_DYNAMIC			(1 << 1)
#define  EN_AGE_PORT			(1 << 2)
#define  EN_AGE_VLAN			(1 << 3)
#define  EN_AGE_SPT			(1 << 4)
#define  EN_AGE_MCAST			(1 << 5)
#define  FAST_AGE_STR_DONE		(1 << 7)

#define CORE_FAST_AGE_PORT		0x00224
#define  AGE_PORT_MASK			0xf

#define CORE_FAST_AGE_VID		0x00228
#define  AGE_VID_MASK			0x3fff

#define CORE_LNKSTS			0x00400
#define  LNK_STS_MASK			0x1ff

#define CORE_SPDSTS			0x00410
#define  SPDSTS_10			0
#define  SPDSTS_100			1
#define  SPDSTS_1000			2
#define  SPDSTS_SHIFT			2
#define  SPDSTS_MASK			0x3

#define CORE_DUPSTS			0x00420
#define  CORE_DUPSTS_MASK		0x1ff

#define CORE_PAUSESTS			0x00428
#define  PAUSESTS_TX_PAUSE_SHIFT	9

#define CORE_GMNCFGCFG			0x0800
#define  RST_MIB_CNT			(1 << 0)
#define  RXBPDU_EN			(1 << 1)

#define CORE_IMP0_PRT_ID		0x0804

#define CORE_BRCM_HDR_CTRL		0x0080c
#define  BRCM_HDR_EN_P8			(1 << 0)
#define  BRCM_HDR_EN_P5			(1 << 1)
#define  BRCM_HDR_EN_P7			(1 << 2)

#define CORE_BRCM_HDR_CTRL2		0x0828

#define CORE_HL_PRTC_CTRL		0x0940
#define  ARP_EN				(1 << 0)
#define  RARP_EN			(1 << 1)
#define  DHCP_EN			(1 << 2)
#define  ICMPV4_EN			(1 << 3)
#define  ICMPV6_EN			(1 << 4)
#define  ICMPV6_FWD_MODE		(1 << 5)
#define  IGMP_DIP_EN			(1 << 8)
#define  IGMP_RPTLVE_EN			(1 << 9)
#define  IGMP_RTPLVE_FWD_MODE		(1 << 10)
#define  IGMP_QRY_EN			(1 << 11)
#define  IGMP_QRY_FWD_MODE		(1 << 12)
#define  IGMP_UKN_EN			(1 << 13)
#define  IGMP_UKN_FWD_MODE		(1 << 14)
#define  MLD_RPTDONE_EN			(1 << 15)
#define  MLD_RPTDONE_FWD_MODE		(1 << 16)
#define  MLD_QRY_EN			(1 << 17)
#define  MLD_QRY_FWD_MODE		(1 << 18)

#define CORE_RST_MIB_CNT_EN		0x0950

#define CORE_BRCM_HDR_RX_DIS		0x0980
#define CORE_BRCM_HDR_TX_DIS		0x0988

#define CORE_ARLA_NUM_ENTRIES		1024

#define CORE_ARLA_RWCTL			0x1400
#define  ARL_RW				(1 << 0)
#define  IVL_SVL_SELECT			(1 << 6)
#define  ARL_STRTDN			(1 << 7)

#define CORE_ARLA_MAC			0x1408
#define CORE_ARLA_VID			0x1420
#define  ARLA_VIDTAB_INDX_MASK		0x1fff

#define CORE_ARLA_MACVID0		0x1440
#define  MAC_MASK			0xffffffffff
#define  VID_SHIFT			48
#define  VID_MASK			0xfff

#define CORE_ARLA_FWD_ENTRY0		0x1460
#define  PORTID_MASK			0x1ff
#define  ARL_CON_SHIFT			9
#define  ARL_CON_MASK			0x3
#define  ARL_PRI_SHIFT			11
#define  ARL_PRI_MASK			0x7
#define  ARL_AGE			(1 << 14)
#define  ARL_STATIC			(1 << 15)
#define  ARL_VALID			(1 << 16)

#define CORE_ARLA_MACVID_ENTRY(x)	(CORE_ARLA_MACVID0 + ((x) * 0x40))
#define CORE_ARLA_FWD_ENTRY(x)		(CORE_ARLA_FWD_ENTRY0 + ((x) * 0x40))

#define CORE_ARLA_SRCH_CTL		0x1540
#define  ARLA_SRCH_VLID			(1 << 0)
#define  IVL_SVL_SELECT			(1 << 6)
#define  ARLA_SRCH_STDN			(1 << 7)

#define CORE_ARLA_SRCH_ADR		0x1544
#define  ARLA_SRCH_ADR_VALID		(1 << 15)

#define CORE_ARLA_SRCH_RSLT_0_MACVID	0x1580
#define CORE_ARLA_SRCH_RSLT_0		0x15a0

#define CORE_ARLA_SRCH_RSLT_MACVID(x)	(CORE_ARLA_SRCH_RSLT_0_MACVID + ((x) * 0x40))
#define CORE_ARLA_SRCH_RSLT(x)		(CORE_ARLA_SRCH_RSLT_0 + ((x) * 0x40))

#define CORE_ARLA_VTBL_RWCTRL		0x1600
#define  ARLA_VTBL_CMD_WRITE		0
#define  ARLA_VTBL_CMD_READ		1
#define  ARLA_VTBL_CMD_CLEAR		2
#define  ARLA_VTBL_STDN			(1 << 7)

#define CORE_ARLA_VTBL_ADDR		0x1604
#define  VTBL_ADDR_INDEX_MASK		0xfff

#define CORE_ARLA_VTBL_ENTRY		0x160c
#define  FWD_MAP_MASK			0x1ff
#define  UNTAG_MAP_MASK			0x1ff
#define  UNTAG_MAP_SHIFT		9
#define  MSTP_INDEX_MASK		0x7
#define  MSTP_INDEX_SHIFT		18
#define  FWD_MODE			(1 << 21)

#define CORE_MEM_PSM_VDD_CTRL		0x2380
#define  P_TXQ_PSM_VDD_SHIFT		2
#define  P_TXQ_PSM_VDD_MASK		0x3
#define  P_TXQ_PSM_VDD(x)		(P_TXQ_PSM_VDD_MASK << \
					((x) * P_TXQ_PSM_VDD_SHIFT))

#define	CORE_P0_MIB_OFFSET		0x8000
#define P_MIB_SIZE			0x400
#define CORE_P_MIB_OFFSET(x)		(CORE_P0_MIB_OFFSET + (x) * P_MIB_SIZE)

#define CORE_PORT_VLAN_CTL_PORT(x)	(0xc400 + ((x) * 0x8))
#define  PORT_VLAN_CTRL_MASK		0x1ff

#define CORE_VLAN_CTRL0			0xd000
#define  CHANGE_1P_VID_INNER		(1 << 0)
#define  CHANGE_1P_VID_OUTER		(1 << 1)
#define  CHANGE_1Q_VID			(1 << 3)
#define  VLAN_LEARN_MODE_SVL		(0 << 5)
#define  VLAN_LEARN_MODE_IVL		(3 << 5)
#define  VLAN_EN			(1 << 7)

#define CORE_VLAN_CTRL1			0xd004
#define  EN_RSV_MCAST_FWDMAP		(1 << 2)
#define  EN_RSV_MCAST_UNTAG		(1 << 3)
#define  EN_IPMC_BYPASS_FWDMAP		(1 << 5)
#define  EN_IPMC_BYPASS_UNTAG		(1 << 6)

#define CORE_VLAN_CTRL2			0xd008
#define  EN_MIIM_BYPASS_V_FWDMAP	(1 << 2)
#define  EN_GMRP_GVRP_V_FWDMAP		(1 << 5)
#define  EN_GMRP_GVRP_UNTAG_MAP		(1 << 6)

#define CORE_VLAN_CTRL3			0xd00c
#define  EN_DROP_NON1Q_MASK		0x1ff

#define CORE_VLAN_CTRL4			0xd014
#define  RESV_MCAST_FLOOD		(1 << 1)
#define  EN_DOUBLE_TAG_MASK		0x3
#define  EN_DOUBLE_TAG_SHIFT		2
#define  EN_MGE_REV_GMRP		(1 << 4)
#define  EN_MGE_REV_GVRP		(1 << 5)
#define  INGR_VID_CHK_SHIFT		6
#define  INGR_VID_CHK_MASK		0x3
#define  INGR_VID_CHK_FWD		(0 << INGR_VID_CHK_SHIFT)
#define  INGR_VID_CHK_DROP		(1 << INGR_VID_CHK_SHIFT)
#define  INGR_VID_CHK_NO_CHK		(2 << INGR_VID_CHK_SHIFT)
#define  INGR_VID_CHK_VID_VIOL_IMP	(3 << INGR_VID_CHK_SHIFT)

#define CORE_VLAN_CTRL5			0xd018
#define  EN_CPU_RX_BYP_INNER_CRCCHCK	(1 << 0)
#define  EN_VID_FFF_FWD			(1 << 2)
#define  DROP_VTABLE_MISS		(1 << 3)
#define  EGRESS_DIR_FRM_BYP_TRUNK_EN	(1 << 4)
#define  PRESV_NON1Q			(1 << 6)

#define CORE_VLAN_CTRL6			0xd01c
#define  STRICT_SFD_DETECT		(1 << 0)
#define  DIS_ARL_BUST_LMIT		(1 << 4)

#define CORE_DEFAULT_1Q_TAG_P(x)	(0xd040 + ((x) * 8))
#define  CFI_SHIFT			12
#define  PRI_SHIFT			13
#define  PRI_MASK			0x7

#define CORE_JOIN_ALL_VLAN_EN		0xd140

#define CORE_EEE_EN_CTRL		0x24800
#define CORE_EEE_LPI_INDICATE		0x24810

#endif /* __BCM_SF2_REGS_H */
