begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* "@(#)htboot.c	7.1 (Berkeley) 6/5/86" */
end_comment

begin_comment
comment|/*  * VAX tape boot block for distribution tapes  * works on massbus tu10/te16/tu45/tu77  *  * reads a program from a tp directory on a tape and executes it  * program must be stripped of the header and is loaded ``bits as is''  * you can return to this loader via ``ret'' as you are called ``calls $0,ent''  */
end_comment

begin_expr_stmt
operator|.
name|set
name|RELOC
operator|,
literal|0x70000
comment|/* a.out defines */
operator|.
name|set
name|HDRSIZ
operator|,
literal|040
comment|/* size of file header for VAX */
operator|.
name|set
name|MAGIC
operator|,
literal|0410
comment|/* file type id in header */
operator|.
name|set
name|TSIZ
operator|,
literal|4
comment|/* text size */
operator|.
name|set
name|DSIZ
operator|,
literal|8
comment|/* data size */
operator|.
name|set
name|BSIZ
operator|,
literal|12
comment|/* bss size */
operator|.
name|set
name|TENT
operator|,
literal|024
comment|/* task header entry loc */
comment|/* tp directory definitions */
operator|.
name|set
name|FILSIZ
operator|,
literal|38
comment|/* tp direc offset for file size */
operator|.
name|set
name|BNUM
operator|,
literal|44
comment|/* tp dir offset for start block no. */
operator|.
name|set
name|ENTSIZ
operator|,
literal|64
comment|/* size of 1 TP dir entry, bytes */
operator|.
name|set
name|PTHSIZ
operator|,
literal|32
comment|/* size of TP path name, bytes */
operator|.
name|set
name|BLKSIZ
operator|,
literal|512
comment|/* tape block size, bytes */
operator|.
name|set
name|NUMDIR
operator|,
literal|24
comment|/* no. of dir blocks on tape */
operator|.
name|set
name|ENTBLK
operator|,
literal|8
comment|/* no. of dir entries per tape block */
comment|/* processor registers and bits */
operator|.
name|set
name|RXCS
operator|,
literal|32
operator|.
name|set
name|RXDB
operator|,
literal|33
operator|.
name|set
name|TXCS
operator|,
literal|34
operator|.
name|set
name|TXDB
operator|,
literal|35
operator|.
name|set
name|RXCS_DONE
operator|,
literal|0x80
operator|.
name|set
name|TXCS_RDY
operator|,
literal|0x80
operator|.
name|set
name|TXCS_pr
operator|,
literal|7
comment|/* bit position of TXCS ready bit */
operator|.
name|set
name|RXCS_pd
operator|,
literal|7
comment|/* bit position of RXCS done bit */
comment|/* MBA registers */
operator|.
name|set
name|MBA_CSR
operator|,
literal|0
comment|/* configuration and status register */
operator|.
name|set
name|MBA_CR
operator|,
literal|4
comment|/* MBA control reg */
operator|.
name|set
name|MBA_SR
operator|,
literal|8
comment|/* MBA status reg */
operator|.
name|set
name|MBA_VAR
operator|,
literal|12
comment|/* MBA virt addr reg */
operator|.
name|set
name|MBA_BCR
operator|,
literal|16
comment|/* MBA byte count reg */
operator|.
name|set
name|MBA_MAP
operator|,
literal|0x800
comment|/* start of MBA map reg's */
operator|.
name|set
name|MRV
operator|,
literal|0x80000000
comment|/* TE16/TU45/TU77 mba registers */
operator|.
name|set
name|HTCS1
operator|,
literal|0
comment|/* HT control 1 reg */
operator|.
name|set
name|HTDS
operator|,
literal|4
comment|/* status reg */
operator|.
name|set
name|HTER
operator|,
literal|8
comment|/* error reg */
operator|.
name|set
name|HTAS
operator|,
literal|16
comment|/* attention summary */
operator|.
name|set
name|HTFC
operator|,
literal|20
comment|/* frame count */
operator|.
name|set
name|HTTC
operator|,
literal|36
comment|/* HT tape control */
comment|/* HT commands */
operator|.
name|set
name|GO
operator|,
literal|1
comment|/* GO bit */
operator|.
name|set
name|HT_REW
operator|,
literal|6
comment|/* rewind, on-line */
operator|.
name|set
name|HT_DCLR
operator|,
literal|010
comment|/* drive clear */
operator|.
name|set
name|HT_SREV
operator|,
literal|032
comment|/* space reverse */
operator|.
name|set
name|HT_RCOM
operator|,
literal|070
comment|/* read forward */
comment|/* HT bits */
operator|.
name|set
name|ERR
operator|,
literal|040000
comment|/* composite error bit in status reg */
operator|.
name|set
name|TCHAR
operator|,
literal|012300
comment|/* unit 0, odd parity, PDP11, 1600 BPI NRZ, */
comment|/* abort on error - for tape controller */
operator|.
name|set
name|DRDY
operator|,
literal|0200
comment|/* HT/drive ready in status reg */
operator|.
name|set
name|HT_pd
operator|,
literal|7
comment|/* bit position of HT DRDY bit */
operator|.
name|set
name|HT_pe
operator|,
literal|14
comment|/* bit position of HT ERROR bit */
comment|/* local stack variables */
operator|.
name|set
name|tapa
operator|,
operator|-
literal|4
comment|/* desired tape addr */
operator|.
name|set
name|mtapa
operator|,
operator|-
literal|8
comment|/* current tape addr */
operator|.
name|set
name|name
operator|,
operator|-
literal|8
operator|-
name|PTHSIZ
comment|/* operator-typed file name */
comment|/* register usage */
operator|.
name|set
name|rMBA
operator|,
name|r10
operator|.
name|set
name|rHT
operator|,
name|r11
comment|/* initialization */
name|init
operator|:
name|mull2
name|$0x80
operator|,
operator|%
name|rHT
name|addl2
name|$0x400
operator|,
operator|%
name|rHT
name|addl2
operator|%
name|rMBA
operator|,
operator|%
name|rHT
name|movl
name|$RELOC
operator|,
name|fp
comment|/* core loc to which to move this program */
name|addl3
name|$name
operator|,
name|fp
operator|,
name|sp
comment|/* set stack pointer, leaving room for locals */
name|clrl
name|r0
literal|1
operator|:
name|movc3
name|$end
operator|,
operator|(
name|r0
operator|)
operator|,
operator|(
name|fp
operator|)
comment|/* move boot up to relocated position */
name|jmp
name|start
operator|+
name|RELOC
name|start
operator|:
name|movl
name|$1
operator|,
name|MBA_CR
argument_list|(
argument|%rMBA
argument_list|)
comment|/* MBA init */
name|movl
name|$TCHAR
operator|,
name|HTTC
argument_list|(
argument|%rHT
argument_list|)
comment|/* drive no., etc. */
name|movl
name|$HT_DCLR
operator|+
name|GO
operator|,
name|HTCS1
argument_list|(
argument|%rHT
argument_list|)
comment|/* drive clear */
name|bsbw
name|rew
comment|/* rewind input tape */
name|movab
name|name
argument_list|(
name|fp
argument_list|)
operator|,
name|r4
comment|/* start of filename storage */
name|movzbl
name|$
literal|'=,r0			/* prompt character */ 	bsbw	putc			/* output char to main console */ /* read in a file name */ 	movl	r4,r1			/* loc at which to store file name */ nxtc: 	bsbw	getc			/* get input char'
name|s
name|in
name|file
name|name
operator|*
operator|/
name|cmpb
name|r0
operator|,
name|$012
comment|/* terminator ? */
name|beql
name|nullc
name|movb
name|r0
operator|,
operator|(
name|r1
operator|)
operator|+
name|brb
name|nxtc
name|nullc
operator|:
name|subl3
name|r4
operator|,
name|r1
operator|,
name|r9
comment|/* size of path name */
name|beql
name|start
comment|/* dumb operator */
name|clrb
argument_list|(
name|r1
argument_list|)
operator|+
name|incl
name|r9
comment|/* user-specified TP filename has been stored at name(fp) */
comment|/* read in entire tp directory contents into low core */
name|dirred
operator|:
name|movl
name|$8
operator|,
name|tapa
argument_list|(
argument|fp
argument_list|)
comment|/* tp directory starts at block 8 */
name|movl
name|$
argument_list|(
name|NUMDIR
operator|*
name|BLKSIZ
argument_list|)
operator|,
name|r6
comment|/* no. bytes in total dir */
name|bsbw
name|taper
comment|/* read no. bytes indicated */
comment|/* search entire directory for user-specified file name */
name|clrl
name|r5
comment|/* dir buff loc = 0 */
name|nxtdir
operator|:
name|cmpc3
name|r9
operator|,
operator|(
name|r5
operator|)
operator|,
operator|(
name|r4
operator|)
comment|/* see if dir entry matches filename */
name|beql
name|fndfil
comment|/* found match */
name|acbl
name|$NUMDIR
operator|*
name|BLKSIZ
operator|-
literal|1
operator|,
name|$ENTSIZ
operator|,
name|r5
operator|,
name|nxtdir
comment|/* see if done with tp dir */
name|brw
name|start
comment|/* entry not in directory; start over */
comment|/* found desired tp dir entry */
name|fndfil
operator|:
name|movzwl
name|BNUM
argument_list|(
name|r5
argument_list|)
operator|,
name|tapa
argument_list|(
argument|fp
argument_list|)
comment|/* start block no., 2 bytes */
name|addl2
name|$7
operator|,
name|tapa
argument_list|(
argument|fp
argument_list|)
comment|/* skip 7 boot blocks */
name|movzwl
name|FILSIZ
argument_list|(
name|r5
argument_list|)
operator|,
name|r6
comment|/* low 2 bytes file size */
name|insv
name|FILSIZ
operator|-
literal|1
operator|(
name|r5
operator|)
operator|,
name|$16
operator|,
name|$8
operator|,
name|r6
comment|/* file size, high byte */
name|cmpl
name|r6
operator|,
name|$RELOC
operator|-
literal|512
comment|/* check if file fits below stack */
name|blss
name|filok
comment|/* file o.k. */
name|brw
name|start
comment|/* file too large */
comment|/* time to read in desired file from tape */
name|filok
operator|:
name|movl
name|r6
operator|,
name|r7
comment|/* save r6 */
name|bsbb
name|taper
name|bsbw
name|rew
comment|/* clear core */
name|subl3
name|r7
operator|,
name|$RELOC
operator|-
literal|4
operator|,
name|r0
comment|/* no. bytes to clear */
literal|1
operator|:
name|clrb
argument_list|(
name|r7
argument_list|)
operator|+
name|sobgtr
name|r0
operator|,
literal|1b
comment|/* time to jump to start of file& execute */
name|addl3
name|$20
operator|,
name|fp
operator|,
name|ap
name|clrl
name|r5
name|calls
name|$0
operator|,
operator|(
name|r5
operator|)
name|brw
name|start
comment|/* taper: movcTAPE (r6),tapa(fp),0 */
name|rew2
operator|:
name|bsbb
name|rew
comment|/* beginning of tape */
name|taper0
operator|:
name|bsbb
name|rrec
comment|/* advance 1 block; never want blk0 */
name|taper
operator|:
name|clrl
name|r0
comment|/* page no. */
name|cmpl
name|mtapa
argument_list|(
name|fp
argument_list|)
operator|,
name|tapa
argument_list|(
argument|fp
argument_list|)
comment|/* current position .vs. desired */
name|bgtr
name|rew2
name|blss
name|taper0
literal|1
operator|:
name|bsbb
name|rrec
name|acbl
name|$1
operator|,
name|$
operator|-
name|BLKSIZ
operator|,
name|r6
operator|,
literal|1b
name|rsb
comment|/* rew: rewind the tape */
name|rew
operator|:
name|clrl
name|mtapa
argument_list|(
argument|fp
argument_list|)
comment|/* current position */
name|movl
name|$HT_REW
operator|+
name|GO
operator|,
name|HTCS1
argument_list|(
argument|%rHT
argument_list|)
comment|/* rewind */
name|rsb
comment|/* rrec: read 1 block from mag tape into page (r0) */
name|rrec
operator|:
comment|/* pushl r0; movzbl $'r,r0; bsbw putc; movl (sp)+,r0; */
name|movl
name|HTDS
argument_list|(
operator|%
name|rHT
argument_list|)
operator|,
name|r2
name|bbc
name|$HT_pd
operator|,
name|r2
operator|,
name|rrec
comment|/* HT& drive ready ? */
name|movl
name|$
operator|-
name|BLKSIZ
operator|,
name|MBA_BCR
argument_list|(
argument|%rMBA
argument_list|)
name|bisl3
name|$MRV
operator|,
name|r0
operator|,
name|MBA_MAP
argument_list|(
argument|%rMBA
argument_list|)
name|clrl
name|MBA_VAR
argument_list|(
argument|%rMBA
argument_list|)
name|movl
name|$HT_RCOM
operator|+
name|GO
operator|,
name|HTCS1
argument_list|(
operator|%
name|rHT
argument_list|)
comment|/* read forward */
literal|1
operator|:
name|movl
name|HTDS
argument_list|(
operator|%
name|rHT
argument_list|)
operator|,
name|r2
name|bbc
name|$HT_pd
operator|,
name|r2
operator|,
literal|1b
name|movl
name|HTER
argument_list|(
operator|%
name|rHT
argument_list|)
operator|,
name|r2
name|bbc
name|$HT_pe
operator|,
name|r2
operator|,
literal|2f
comment|/* any read errors ? */
name|clrl
name|HTDS
argument_list|(
argument|%rHT
argument_list|)
comment|/* clear status - try to recover */
name|mnegl
name|$1
operator|,
name|HTFC
argument_list|(
argument|%rHT
argument_list|)
comment|/* frame count for backspace */
name|movl
name|$HT_SREV
operator|+
name|GO
operator|,
name|HTCS1
argument_list|(
argument|%rHT
argument_list|)
comment|/* space reverse */
name|brb
name|rrec
literal|2
operator|:
name|incl
name|r0
comment|/* next page no. */
name|incl
name|mtapa
argument_list|(
argument|fp
argument_list|)
comment|/* mag tape block position */
name|rsb
name|getc
operator|:
name|mfpr
name|$RXCS
operator|,
name|r0
name|bbc
name|$RXCS_pd
operator|,
name|r0
operator|,
name|getc
comment|/* receiver ready ? */
name|mfpr
name|$RXDB
operator|,
name|r0
name|extzv
name|$0
operator|,
name|$7
operator|,
name|r0
operator|,
name|r0
name|cmpb
name|r0
operator|,
name|$015
name|bneq
name|putc
name|bsbb
name|putc
name|movb
name|$0
operator|,
name|r0
name|bsbb
name|putc
name|movb
name|$012
operator|,
name|r0
name|putc
operator|:
name|mfpr
name|$TXCS
operator|,
name|r2
name|bbc
name|$TXCS_pr
operator|,
name|r2
operator|,
name|putc
comment|/* transmitter ready ? */
name|extzv
name|$0
operator|,
name|$7
operator|,
name|r0
operator|,
name|r0
name|mtpr
name|r0
operator|,
name|$TXDB
name|rsb
name|end
operator|:
end_expr_stmt

end_unit

