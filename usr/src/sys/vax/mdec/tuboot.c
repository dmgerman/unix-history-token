begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/* "@(#)tuboot.c	7.2 (Berkeley) 8/28/86" */
end_comment

begin_comment
comment|/*  * VAX tu58 console cassette boot block  *  * Helge Skrivervik CSRG/UCB 18jun83  *  * Reads a program from a rt-11 directory on tape  * and executes it.  Programs must be stripped of  * the header and is loaded ``bits as is''.  * You can return to this loader via ``ret'' as  * you are called ``calls $0,ent''.  * Error checking and recovery is almost nonexistant  * due to the severe space constraints.  *  * NOTE: Any changes to this program are likely to  *	 bring the size over 512 bytes ....  *  * Based on tp format bootstrap originally written by Thomas Ferrin.  *  */
end_comment

begin_expr_stmt
operator|.
name|set
name|CTABLE
operator|,
literal|0x400
comment|/* where to load the rad50 cnv table */
operator|.
name|set
name|RELOC
operator|,
literal|0x70000
comment|/* rt-11 directory definitions */
operator|.
name|set
name|DIRBLK
operator|,
literal|6
comment|/* rt-11 directory starts at block 6 */
operator|.
name|set
name|FILSIZ
operator|,
literal|8
comment|/* rt-11 direc entry offset for file size */
operator|.
name|set
name|ENTSIZ
operator|,
literal|14
comment|/* size of 1 rt-11 dir entry, bytes */
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
literal|2
comment|/* no. of dir blocks on tape */
operator|.
name|set
name|FNSIZ
operator|,
literal|8
comment|/* size of rad50 filename + 2 */
operator|.
name|set
name|NAME
operator|,
literal|2
comment|/* direc entry offset for filename */
operator|.
name|set
name|STATUS
operator|,
literal|1
comment|/* direc entry offset for entry status */
comment|/* rt-11 directory entry status */
operator|.
name|set
name|RT_ESEG
operator|,
literal|8
comment|/* end of directory segment */
operator|.
name|set
name|RT_NULL
operator|,
literal|2
comment|/* empty entry */
operator|.
name|set
name|RT_FILE
operator|,
literal|4
comment|/* valid file entry */
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
comment|/* console storage registers and bits */
operator|.
name|set
name|CSRS
operator|,
literal|0x1c
operator|.
name|set
name|CSRD
operator|,
literal|0x1d
operator|.
name|set
name|CSTS
operator|,
literal|0x1e
operator|.
name|set
name|CSTD
operator|,
literal|0x1f
comment|/* TU commands and bits */
operator|.
name|set
name|TU_BREAK
operator|,
literal|1
operator|.
name|set
name|TU_INIT
operator|,
literal|4
operator|.
name|set
name|TU_CONTINUE
operator|,
literal|16
operator|.
name|set
name|TU_READY
operator|,
literal|7
comment|/* bit position of CSRS ready bit */
operator|.
name|set
name|TU_PACKETLEN
operator|,
literal|8
comment|/* length of readcom block */
comment|/* local stack variables */
operator|.
name|set
name|ext
operator|,
operator|-
literal|4
comment|/* file ext. */
operator|.
name|set
name|name
operator|,
operator|-
literal|20
comment|/* 12 bytes for full name */
operator|.
name|set
name|rt_name
operator|,
operator|-
literal|20
operator|-
name|FNSIZ
comment|/* rad50 file name */
comment|/* reboot flags for boot */
operator|.
name|set
name|RB_ASK
operator|,
literal|3
comment|/* ask name and come up single user */
comment|/*   * Initialization.  */
name|init
operator|:
operator|.
name|word
literal|0
comment|/* entry mask for dec monitor */
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nop
comment|/* some no-ops for 750 boot rom to skip */
name|nop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nop
name|movl
name|$RELOC
decl_stmt|,
name|fp
comment|/* core loc to which to move this program */
name|addl3
name|$rt_name
decl_stmt|,
name|fp
decl_stmt|,
name|sp
comment|/* set stack pointer; leave room for locals */
name|clrl
name|r0
decl|1
range|:
name|movc3
name|$end
decl_stmt|,
argument_list|(
name|r0
argument_list|)
decl_stmt|,
argument_list|(
name|fp
argument_list|)
comment|/* move boot up to relocated position */
name|jmp
name|start
decl|+
name|RELOC
name|start
range|:
name|mtpr
name|$TU_BREAK
decl_stmt|,
name|$CSTS
comment|/* set break condition */
name|clrl
name|r2
comment|/* nulls */
name|bsbw
name|xmit2
comment|/* wait 2 character times */
name|mfpr
name|$CSRD
decl_stmt|,
name|r2
comment|/* clear receive buffer */
name|movzwl
name|$TU_INIT
decl||
argument_list|(
name|TU_INIT
operator|<<
literal|8
argument_list|)
decl_stmt|,
name|r2
comment|/* load 2 INIT opcodes */
name|bsbw
name|xmit2
comment|/* xmit 'em */
decl|1
range|:
name|mfpr
name|$CSRD
decl_stmt|,
name|r7
comment|/* get recv data */
name|cmpb
name|r7
decl_stmt|,
name|$TU_CONTINUE
comment|/* is it a continue flag? */
name|bneq
decl|1b
comment|/* nope, look more */
name|movab
name|name
argument_list|(
name|fp
argument_list|)
decl_stmt|,
name|r4
comment|/* start of filename storage */
name|clrq
argument_list|(
name|r4
argument_list|)
comment|/* init name field */
name|clrq
name|name
decl|+8
argument_list|(
name|fp
argument_list|)
name|clrq
name|rt_name
argument_list|(
name|fp
argument_list|)
comment|/* init rad50 filename */
name|movzbl
name|$
decl|'=,r0			/* prompt character */ 	bsbw	putc			/* output char to main console */  /*   * Read in a file name from console.   */ 	movl	r4,r1			/* loc at which to store file name */ nxtc: 	bsbw	getc			/* get input char'
name|s
name|in
name|file
name|name
modifier|*
decl|/
name|cmpb
name|r0
decl_stmt|,
name|$012
comment|/* terminator ? */
name|beql
name|nullc
name|movb
name|r0
decl_stmt|,
argument_list|(
name|r1
argument_list|)
decl_stmt|+
name|brb
name|nxtc
name|nullc
range|:
name|cmpl
name|r4
decl_stmt|,
name|r1
name|beql
name|start
comment|/* restart if empty string */
name|clrb
argument_list|(
name|r1
argument_list|)
comment|/* add null byte at end */
comment|/*  * User-specified filename has been stored at name(fp),  * read the entire directory contents into low core.  */
name|dirred
range|:
name|movl
name|$DIRBLK
decl_stmt|,
name|r10
comment|/* directory starts at block DIRBLK */
name|movl
name|$
argument_list|(
name|NUMDIR
operator|*
name|BLKSIZ
argument_list|)
decl_stmt|,
name|r6
comment|/* no. bytes in total dir */
name|clrl
name|r11
comment|/* start address */
name|bsbw
name|taper
comment|/* read no. bytes indicated */
comment|/*  * Read in the character conversion table which reside in block 1  * (the second block) on the cassette. Place it after the directory  * on low core (from 0x400).  */
name|movl
name|$1
decl_stmt|,
name|r10
comment|/* block number */
name|movl
name|$BLKSIZ
decl_stmt|,
name|r6
comment|/* read one block */
name|bsbw
name|taper
comment|/*  * Convert the ascii filename to rad50.  * R4 still points to name(fp)  */
name|movl
name|$6
decl_stmt|,
name|r3
comment|/* max length of filename */
decl|1
range|:
name|cmpb
name|$
literal|'.,(r4)+		/* look for '
operator|.
literal|' */ 	beql	1f 	sobgtr	r3,1b 	incl	r4			/* point past '
operator|.
literal|' if ext is present */ 1: 	clrb	-1(r4)			/* end name with null */ 	movl	$3,r3			/* max length of extension */ 	movab	ext(fp),r5		/* place extension here */ 1: 	movb	(r4)+,(r5)+ 	beql	1f			/* the string is null terminated */ 	sobgtr	r3,1b 1: 	movab	name(fp),r4 	movab	rt_name(fp),r5		/* ptr to rad50 name */ 	bsbw	rad50			/* convert filename */ 	movab	ext(fp),r4 	movab	rt_name+4(fp),r5 	bsbw	rad50			/* convert extension */  /*  * Search entire directory for user-specified file name.  */  	movab	rt_name(fp),r4		/* search for this file */ 	movl	$10,r5			/* point to first file entry */ 	movzwl	-2(r5),r10		/* r10 = block # where files begin */ 2: 	cmpc3	$6,NAME(r5),(r4)	/* see if dir entry matches filename */ 	beql	fndfil			/* found match */ 1: 	addw2	FILSIZ(r5),r10		/* add file length to block pointer */ 	addl2	$ENTSIZ,r5		/* move to next entry */ /*	cpmb	STATUS(r5),$RT_NULL	/* check if deleted file */ /*	beql	1b /* not really necessary since deleted entries will fail */ 		   /* to compare anyway */ 	cmpb	STATUS(r5),$RT_ESEG	/* check if end of segment */ 	bneq	2b 	brw	start			/* entry not in directory; start over */  /*   * Found desired directory entry   */ fndfil: 					/* start block no., 2 bytes in r10 */ 	movzwl	FILSIZ(r5),r6		/* file size (blocks) */ 	mull2	$BLKSIZ,r6		/* file size (bytes) */ 	cmpl	r6,$RELOC-512		/* check if file fits below stack */ 	blss	filok 	brw	start			/* file too large */  /*   * Read in desired file from tape.  */ filok: 	movl	r6,r5			/* start of bss space */ 	clrl	r11			/* start address */ 	bsbb	taper  /*   * Clear core.  */ 	subl3	r5,$RELOC-4,r0		/* no. bytes to clear */ 1: 	clrb	(r5)+ 	sobgtr	r0,1b  /*   * Jump to start of file& execute.  */ 	addl3	$20,fp,ap		/* ?? */ 	clrl	r5 	movl	$RB_ASK,r11 	calls	$0,(r5) bad: 	brw	start  /*   * Read (r6) bytes from block (r10)   * into loc (r11).  */ taper: 	clrl	r8			/* initialize checksum */ 	movab	readcom,r0		/* read command packet addr */ 	movzbl	$TU_PACKETLEN/2,r1	/* size of readcom block */ 1: 	movzwl	(r0)+,r2		/* get 2 chars from block */ 	bsbb	xmit			/* xmit and update ckecksum */ 	sobgtr	r1,1b			/* loop if more */  /*   * Now do variable part of packet.   */ 	movl	r6,r2			/* byte count */ 	bsbb	xmit 	movl	r10,r2			/* starting block number */ 	bsbb	xmit 	movzwl	r8,r2			/* accumulated ckecksum */ 	bsbb	xmit  /*   * Collect read packet from device.   */ 1: 	bsbb	recv2			/* get 2 packet characters */ 	decb	r2			/* data packet? */ 	bneq	1f			/* branch on end of data */ 	movzbl	r1,r8			/* get byte count of packet */  /*   * Read data into memory.  */ 2: 	bsbb	recv1			/* get a char */ 	movb	r1,(r11)+		/* stuff into memory */ 	sobgtr	r8,2b			/* loop if more */ 	bsbb	recv2			/* skip checksum */ 	brb	1b			/* read next packet */  /*   * End of data xfer; check for errors.  */ 1: 	bsbb	recv2			/* get success code */ 	tstl	r1			/* error in read? */ 	blss	9f			/* branch if status error */ 	movl	$5,r0 1: 	bsbb	recv2			/* discard 10 bytes */ 	sobgtr	r0,1b 	rsb  /* Fatal error */ 9: 	movab	ermsg,r1 1: 	movb	(r1)+,r0 	beql	bad 	bsbb	putc 	brb	1b  /*   * Update checksum in r8 and xmit 2 characters.  */ xmit: 	addw2	r2,r8			/* update checksum */ 	adwc	$0,r8			/* add  in carry */  /* send the 2 characters contained in r2 */ xmit2: 	bsbb	1f			/* xmit one of '
name|em
operator|*
operator|/
name|ashl
name|$
operator|-
literal|8
decl_stmt|,
name|r2
decl_stmt|,
name|r2
comment|/* get next char */
comment|/* fall into... */
decl|1
range|:
name|mfpr
name|$CSTS
decl_stmt|,
name|r7
comment|/* get xmit status */
name|bbc
name|$TU_READY
decl_stmt|,
name|r7
decl_stmt|,1b
comment|/* loop until ready */
name|mtpr
name|r2
decl_stmt|,
name|$CSTD
comment|/* send char */
name|rsb
comment|/*   * Receive 2 characters, return in r2 and r1.  */
name|recv2
range|:
name|bsbb
name|recv1
comment|/* recv one of 'em */
comment|/* fall into... */
comment|/*   * Receive 1 character.  */
name|recv1
operator|:
name|movzbl
name|r1
decl_stmt|,
name|r2
comment|/* save previous byte */
decl|1
range|:
name|mfpr
name|$CSRS
decl_stmt|,
name|r7
comment|/* get recv status */
name|bbc
name|$TU_READY
decl_stmt|,
name|r7
decl_stmt|,1b
comment|/* loop until ready */
name|mfpr
name|$CSRD
decl_stmt|,
name|r1
comment|/* get char */
name|blss
decl|9b
comment|/* branch on recv error */
name|rsb
name|getc
range|:
name|mfpr
name|$RXCS
decl_stmt|,
name|r0
name|bbc
name|$RXCS_pd
decl_stmt|,
name|r0
decl_stmt|,
name|getc
comment|/* receiver ready ? */
name|mfpr
name|$RXDB
decl_stmt|,
name|r0
name|extzv
name|$0
decl_stmt|,
name|$7
decl_stmt|,
name|r0
decl_stmt|,
name|r0
name|cmpb
name|r0
decl_stmt|,
name|$015
name|bneq
name|putc
comment|/* echo and return */
name|bsbb
name|putc
comment|/* carriage return */
comment|/*	movb	$0,r0	*/
comment|/*	bsbb	putc	*/
comment|/* delay */
name|movb
name|$012
decl_stmt|,
name|r0
comment|/* send line feed and return */
name|putc
range|:
name|mfpr
name|$TXCS
decl_stmt|,
name|r2
name|bbc
name|$TXCS_pr
decl_stmt|,
name|r2
decl_stmt|,
name|putc
comment|/* transmitter ready ? */
name|mtpr
name|r0
decl_stmt|,
name|$TXDB
name|rsb
comment|/*  * Convert the filename given from the console  * to radix 50 (rt-11) format.  */
name|rad50
range|:
name|clrw
name|r1
name|bsbb
name|getb50
comment|/* get next ascii byte, exit if null */
name|mull3
name|$03100
decl_stmt|,
name|r0
decl_stmt|,
name|r1
name|bsbb
name|getb50
name|mull3
name|$050
decl_stmt|,
name|r0
decl_stmt|,
name|r2
name|addl2
name|r2
decl_stmt|,
name|r1
name|bsbb
name|getb50
name|addl2
name|r0
decl_stmt|,
name|r1
comment|/* last byte, just add it in */
name|movw
name|r1
decl_stmt|,
argument_list|(
name|r5
argument_list|)
decl_stmt|+
comment|/* save result */
name|brb
name|rad50
name|getb50
range|:
name|movzbl
argument_list|(
name|r4
argument_list|)
operator|+
decl_stmt|,
name|r0
comment|/* get next ascii byte */
name|beql
decl|1f
comment|/* if zero: end of string */
name|movzbl
name|CTABLE
argument_list|(
name|r0
argument_list|)
decl_stmt|,
name|r0
comment|/* and get the r50 byte from the table*/
name|rsb
decl|1
range|:
name|tstl
argument_list|(
name|sp
argument_list|)
operator|+
comment|/* we're through, get back to where */
comment|/* rad50 was called */
name|movw
name|r1
decl_stmt|,
argument_list|(
name|r5
argument_list|)
comment|/* but first save the result */
name|rsb
operator|.
name|align
decl|2
name|readcom
range|:
operator|.
name|byte
literal|2
comment|/* command packet flag */
operator|.
name|byte
literal|10
comment|/* number of bytes in message */
operator|.
name|byte
literal|2
comment|/* tu read opcode */
operator|.
name|byte
literal|0
comment|/* modifier */
operator|.
name|byte
literal|0
comment|/* unit number */
operator|.
name|byte
literal|0
comment|/* switches */
operator|.
name|word
literal|0
comment|/* sequence number */
comment|/* byte count and block number follow */
name|ermsg
operator|:
operator|.
name|asciz
literal|"tuerr\r\n"
name|end
operator|:
comment|/*  * Ascii to rad 50 conversion table,  * stored on the second block on the cassette  *  * NOTE: Always make sure this table ends up  * starting at byte 512!!!!  */
operator|.
name|align
literal|2
operator|.
name|data
literal|2
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d00
operator|.
name|long
literal|0x1d1d1d1b
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1c1d1d
operator|.
name|long
literal|0x21201f1e
operator|.
name|long
literal|0x25242322
operator|.
name|long
literal|0x1d1d2726
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x302011d
operator|.
name|long
literal|0x7060504
operator|.
name|long
literal|0xb0a0908
operator|.
name|long
literal|0xf0e0d0c
operator|.
name|long
literal|0x13121110
operator|.
name|long
literal|0x17161514
operator|.
name|long
literal|0x1d1a1918
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x302011d
operator|.
name|long
literal|0x7060504
operator|.
name|long
literal|0xb0a0908
operator|.
name|long
literal|0xf0e0d0c
operator|.
name|long
literal|0x13121110
operator|.
name|long
literal|0x17161514
operator|.
name|long
literal|0x1d1a1918
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1d1d00
operator|.
name|long
literal|0x1d1d1d1b
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x1d1c1d1d
operator|.
name|long
literal|0x21201f1e
operator|.
name|long
literal|0x25242322
operator|.
name|long
literal|0x1d1d2726
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x302011d
operator|.
name|long
literal|0x7060504
operator|.
name|long
literal|0xb0a0908
operator|.
name|long
literal|0xf0e0d0c
operator|.
name|long
literal|0x13121110
operator|.
name|long
literal|0x17161514
operator|.
name|long
literal|0x1d1a1918
operator|.
name|long
literal|0x1d1d1d1d
operator|.
name|long
literal|0x302011d
operator|.
name|long
literal|0x7060504
operator|.
name|long
literal|0xb0a0908
operator|.
name|long
literal|0xf0e0d0c
operator|.
name|long
literal|0x13121110
operator|.
name|long
literal|0x17161514
operator|.
name|long
literal|0x1d1a1918
operator|.
name|long
literal|0x1d1d1d
operator|.
name|data
end_decl_stmt

end_unit

