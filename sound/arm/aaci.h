/*
 *  linux/sound/arm/aaci.c - ARM PrimeCell AACI PL041 driver
 *
 *  Copyright (C) 2003 Deep Blue Solutions, Ltd, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef AACI_H
#define AACI_H

/*
 * Control and status register offsets
 *  P39.
 */
enum {
  AACI_CSCH1 = 0x000,
  AACI_CSCH2 = 0x014,
  AACI_CSCH3 = 0x028,
  AACI_CSCH4 = 0x03c
};

enum {
  AACI_RXCR = 0x000, /* 29 bits Control Rx FIFO */
  AACI_TXCR = 0x004, /* 17 bits Control Tx FIFO */
  AACI_SR = 0x008,   /* 12 bits Status */
  AACI_ISR = 0x00c,  /* 7 bits  Int Status */
  AACI_IE = 0x010    /* 7 bits  Int Enable */
};

/*
 * Other registers
 */
enum {
  AACI_SL1RX = 0x050,
  AACI_SL1TX = 0x054,
  AACI_SL2RX = 0x058,
  AACI_SL2TX = 0x05c,
  AACI_SL12RX = 0x060,
  AACI_SL12TX = 0x064,
  AACI_SLFR = 0x068,    /* slot flags */
  AACI_SLISTAT = 0x06c, /* slot interrupt status */
  AACI_SLIEN = 0x070,   /* slot interrupt enable */
  AACI_INTCLR = 0x074,  /* interrupt clear */
  AACI_MAINCR = 0x078,  /* main control */
  AACI_RESET = 0x07c,   /* reset control */
  AACI_SYNC = 0x080,    /* sync control */
  AACI_ALLINTS = 0x084, /* all fifo interrupt status */
  AACI_MAINFR = 0x088,  /* main flag register */
  AACI_DR1 = 0x090,     /* data read/written fifo 1 */
  AACI_DR2 = 0x0b0,     /* data read/written fifo 2 */
  AACI_DR3 = 0x0d0,     /* data read/written fifo 3 */
  AACI_DR4 = 0x0f0      /* data read/written fifo 4 */
};

/*
 * TX/RX fifo control register (CR). P48
 */
enum {
  CR_FEN = (1 << 16),     /* fifo enable */
  CR_COMPACT = (1 << 15), /* compact mode */
  CR_SZ16 = (0 << 13),    /* 16 bits */
  CR_SZ18 = (1 << 13),    /* 18 bits */
  CR_SZ20 = (2 << 13),    /* 20 bits */
  CR_SZ12 = (3 << 13),    /* 12 bits */
  CR_SL12 = (1 << 12),
  CR_SL11 = (1 << 11),
  CR_SL10 = (1 << 10),
  CR_SL9 = (1 << 9),
  CR_SL8 = (1 << 8),
  CR_SL7 = (1 << 7),
  CR_SL6 = (1 << 6),
  CR_SL5 = (1 << 5),
  CR_SL4 = (1 << 4),
  CR_SL3 = (1 << 3),
  CR_SL2 = (1 << 2),
  CR_SL1 = (1 << 1),
  CR_EN = (1 << 0) /* transmit enable */
};

/*
 * status register bits. P49
 */
enum {
  SR_RXTOFE = (1 << 11), /* rx timeout fifo empty */
  SR_TXTO = (1 << 10),   /* rx timeout fifo nonempty */
  SR_TXU = (1 << 9),     /* tx underrun */
  SR_RXO = (1 << 8),     /* rx overrun */
  SR_TXB = (1 << 7),     /* tx busy */
  SR_RXB = (1 << 6),     /* rx busy */
  SR_TXFF = (1 << 5),    /* tx fifo full */
  SR_RXFF = (1 << 4),    /* rx fifo full */
  SR_TXHE = (1 << 3),    /* tx fifo half empty */
  SR_RXHF = (1 << 2),    /* rx fifo half full */
  SR_TXFE = (1 << 1),    /* tx fifo empty */
  SR_RXFE = (1 << 0)     /* rx fifo empty */
};

/*
 * interrupt status register bits.
 */
enum {
  ISR_RXTOFEINTR = (1 << 6), /* rx fifo empty */
  ISR_URINTR = (1 << 5),     /* tx underflow */
  ISR_ORINTR = (1 << 4),     /* rx overflow */
  ISR_RXINTR = (1 << 3),     /* rx fifo */
  ISR_TXINTR = (1 << 2),     /* tx fifo intr */
  ISR_RXTOINTR = (1 << 1),   /* tx timeout */
  ISR_TXCINTR = (1 << 0)     /* tx complete */
};

/*
 * interrupt enable register bits.
 */
enum {
  IE_RXTOIE = (1 << 6),
  IE_URIE = (1 << 5),
  IE_ORIE = (1 << 4),
  IE_RXIE = (1 << 3),
  IE_TXIE = (1 << 2),
  IE_RXTIE = (1 << 1),
  IE_TXCIE = (1 << 0)
};

/*
 * interrupt status. P51
 */
enum {
  ISR_RXTOFE = (1 << 6), /* rx timeout fifo empty */
  ISR_UR = (1 << 5),     /* tx fifo underrun */
  ISR_OR = (1 << 4),     /* rx fifo overrun */
  ISR_RX = (1 << 3),     /* rx interrupt status */
  ISR_TX = (1 << 2),     /* tx interrupt status */
  ISR_RXTO = (1 << 1),   /* rx timeout */
  ISR_TXC = (1 << 0)     /* tx complete */
};

/*
 * interrupt enable. P52
 */
enum {
  IE_RXTOFE = (1 << 6), /* rx timeout fifo empty */
  IE_UR = (1 << 5),     /* tx fifo underrun */
  IE_OR = (1 << 4),     /* rx fifo overrun */
  IE_RX = (1 << 3),     /* rx interrupt status */
  IE_TX = (1 << 2),     /* tx interrupt status */
  IE_RXTO = (1 << 1),   /* rx timeout */
  IE_TXC = (1 << 0)     /* tx complete */
};

/*
 * slot flag register bits. P56
 */
enum {
  SLFR_RWIS = (1 << 13),      /* raw wake-up interrupt status */
  SLFR_RGPIOINTR = (1 << 12), /* raw gpio interrupt */
  SLFR_12TXE = (1 << 11),     /* slot 12 tx empty */
  SLFR_12RXV = (1 << 10),     /* slot 12 rx valid */
  SLFR_2TXE = (1 << 9),       /* slot 2 tx empty */
  SLFR_2RXV = (1 << 8),       /* slot 2 rx valid */
  SLFR_1TXE = (1 << 7),       /* slot 1 tx empty */
  SLFR_1RXV = (1 << 6),       /* slot 1 rx valid */
  SLFR_12TXB = (1 << 5),      /* slot 12 tx busy */
  SLFR_12RXB = (1 << 4),      /* slot 12 rx busy */
  SLFR_2TXB = (1 << 3),       /* slot 2 tx busy */
  SLFR_2RXB = (1 << 2),       /* slot 2 rx busy */
  SLFR_1TXB = (1 << 1),       /* slot 1 tx busy */
  SLFR_1RXB = (1 << 0)        /* slot 1 rx busy */
};

/*
 * Interrupt clear register.
 */
enum {
  ICLR_RXTOFEC4 = (1 << 12),
  ICLR_RXTOFEC3 = (1 << 11),
  ICLR_RXTOFEC2 = (1 << 10),
  ICLR_RXTOFEC1 = (1 << 9),
  ICLR_TXUEC4 = (1 << 8),
  ICLR_TXUEC3 = (1 << 7),
  ICLR_TXUEC2 = (1 << 6),
  ICLR_TXUEC1 = (1 << 5),
  ICLR_RXOEC4 = (1 << 4),
  ICLR_RXOEC3 = (1 << 3),
  ICLR_RXOEC2 = (1 << 2),
  ICLR_RXOEC1 = (1 << 1),
  ICLR_WISC = (1 << 0)
};

/*
 * Main control register bits. P62
 */
#define MAINCR_SCRA(x)	((x) << 10)	/* secondary codec reg access */
enum {
  MAINCR_DMAEN = (1 << 9),    /* dma enable */
  MAINCR_SL12TXEN = (1 << 8), /* slot 12 transmit enable */
  MAINCR_SL12RXEN = (1 << 7), /* slot 12 receive enable */
  MAINCR_SL2TXEN = (1 << 6),  /* slot 2 transmit enable */
  MAINCR_SL2RXEN = (1 << 5),  /* slot 2 receive enable */
  MAINCR_SL1TXEN = (1 << 4),  /* slot 1 transmit enable */
  MAINCR_SL1RXEN = (1 << 3),  /* slot 1 receive enable */
  MAINCR_LPM = (1 << 2),      /* low power mode */
  MAINCR_LOOPBK = (1 << 1),   /* loopback */
  MAINCR_IE = (1 << 0)        /* aaci interface enable */
};

/*
 * Reset register bits. P65
 */
enum { RESET_NRST = (1 << 0) };

/*
 * Sync register bits. P65
 */
enum { SYNC_FORCE = (1 << 0) };

/*
 * Main flag register bits. P66
 */
enum {
  MAINFR_TXB = (1 << 1), /* transmit busy */
  MAINFR_RXB = (1 << 0)  /* receive busy */
};

struct aaci_runtime {
	void			__iomem *base;
	void			__iomem *fifo;
	spinlock_t		lock;

	struct ac97_pcm		*pcm;
	int			pcm_open;

	u32			cr;
	struct snd_pcm_substream	*substream;

	unsigned int		period;	/* byte size of a "period" */

	/*
	 * PIO support
	 */
	void			*start;
	void			*end;
	void			*ptr;
	int			bytes;
	unsigned int		fifo_bytes;
};

struct aaci {
	struct amba_device	*dev;
	struct snd_card		*card;
	void			__iomem *base;
	unsigned int		fifo_depth;
	unsigned int		users;
	struct mutex		irq_lock;

	/* AC'97 */
	struct mutex		ac97_sem;
	struct snd_ac97_bus	*ac97_bus;
	struct snd_ac97		*ac97;

	u32			maincr;

	struct aaci_runtime	playback;
	struct aaci_runtime	capture;

	struct snd_pcm		*pcm;
};

enum { ACSTREAM_FRONT = 0, ACSTREAM_SURROUND = 1, ACSTREAM_LFE = 2 };

#endif
