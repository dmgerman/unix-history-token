begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tuboot.s	4.1	83/02/16	*/
end_comment

begin_comment
comment|/*  * VAX tu58 console cassette boot block  *  * Thomas Ferrin  27oct82  *  * Reads a program from a tp directory on tape  * and executes it.  Program must be stripped of  * the header and is loaded ``bits as is''.  * You can return to this loader via ``ret'' as  * you are called ``calls $0,ent''.  *   * Helge Skrivervik CSRG/UCB 18jun83  * 	Changed to use rt-11 format directory& files  *	instead of tp format  */
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
name|RT_FNSIZ
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
name|RT_STAT
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
name|RT_FNSIZ
comment|/* rad50 file name */
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
name|$name
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
comment|/* init tu58 */
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
name|clrq
name|rt_name
argument_list|(
name|fp
argument_list|)
comment|/* init rad50 filename */
name|movab
name|name
argument_list|(
name|fp
argument_list|)
decl_stmt|,
name|r4
comment|/* start of filename storage */
name|movzbl
name|$
decl|'=,r0			/* prompt character */ 	bsbw	putc			/* output char to main console */  /* read in a file name */ 	movl	r4,r1			/* loc at which to store file name */ nxtc: 	bsbw	getc			/* get input char'
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
name|subl3
name|r4
decl_stmt|,
name|r1
decl_stmt|,
name|r9
comment|/* size of path name */
name|beql
name|start
comment|/* restart if empty string */
name|clrb
argument_list|(
name|r1
argument_list|)
comment|/* add null byte at end */
name|incl
name|r9
comment|/* and fix length */
comment|/*  * user-specified filename has been stored at name(fp)   * read in entire directory contents into low core   */
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
comment|/*  * Read in the character conversion table which reside in block 1  * (the second block) on the cassette.  */
name|movl
name|$1
decl_stmt|,
name|r10
comment|/* start block */
name|movl
name|$BLKSIZ
decl_stmt|,
name|r6
comment|/* read one block */
name|movl
decl|0x400
decl_stmt|,
name|r11
comment|/* place it after the directory */
name|bsbw
name|taper
comment|/*  * Convert the ascii filename to rad50.  */
name|movab
name|name
argument_list|(
name|fp
argument_list|)
decl_stmt|,
name|r4
comment|/* ptr to ascii name */
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
literal|' */ 	sobgtr	r3,1b 	clrb	-1(r4)			/* end name with null */ 	movl	$3,r3			/* max length of extension */ 	movab	ext(fp),r5		/* place extension here */ 1: 	movb	(r4)+,(r5)+ 	beql	1f			/* the string is null terminated */ 	sobgtr	r3,1b 1: 	movab	name(fp),r4 	movab	rt_name(fp),r5		/* ptr to rad50 name */ 	bsbw	rad50			/* convert filename */ 	movab	ext(fp),r4 	movab	rt_name+4(fp),r5 	bsbw	rad50			/* convert extension */  /*  * Search entire directory for user-specified file name.  */  	movab	rt_name(fp),r4		/* search for this file */ 	movl	$10,r5			/* dir buff loc = 0, point to first */ 					/* file entry */ 	movzwl	-2(r5),r3		/* r3 = block # where files begin */ 2: 	cmpc3	$6,NAME(r5),(r4)	/* see if dir entry matches filename */ 	beql	fndfil			/* found match */ 1: 	addw2	FILSIZ(r5),r3		/* add file length to block pointer */ 	addl2	$ENTSIZ,r5		/* move to next entry */ #	cpmb	RT_STAT(r5),$RT_NULL	/* check if deleted file */ #	beql	1b 	cmpb	RT_STAT(r5),$RT_ESEG	/* check if end of segment */ 	bneq	2b 	brw	start			/* entry not in directory; start over */  /*   * Found desired directory entry   */ fndfil: 	movl	r3,r10			/* start block no., 2 bytes */ 	movzwl	FILSIZ(r5),r6		/* file size (blocks) */ 	mull2	$BLKSIZ,r6		/* file size (bytes) */ #	cmpl	r6,$RELOC-512		/* check if file fits below stack */ #	blss	filok #	brw	start			/* file too large */  /*   * Read in desired file from tape.  */ filok: 	movl	r6,r5			/* start of bss space */ 	clrl	r11			/* start address */ 	bsbb	taper #	bsbb	rew  /*   * Clear core.  */ 	subl3	r5,$RELOC-4,r0		/* no. bytes to clear */ 1: 	clrb	(r5)+ 	sobgtr	r0,1b  /*   * Jump to start of file& execute.  */ 	addl3	$20,fp,ap 	clrl	r5 	calls	$0,(r5) bad: 	brw	start  /* rewind tape */ #ifdef notdef rew: 	movb	$5,readcom+2		/* position opcode */ 	clrl	r10			/* block 0 */ 	clrl	r6			/* 0 bytes */ 	bsbb	taper 	movb	$2,readcom+2		/* read opcode */ 	rsb #endif  /* read (r6) bytes from (r10) into loc (r11) */ taper: 	clrl	r8			/* initialize checksum */ 	movab	readcom,r0		/* read command packet addr */ 	movzbl	$TU_PACKETLEN/2,r1	/* size of readcom block */ 1: 	movzwl	(r0)+,r2		/* get 2 chars from block */ 	bsbb	xmit			/* xmit and update ckecksum */ 	sobgtr	r1,1b			/* loop if more */  	/* now do variable part of packet */ 	movl	r6,r2			/* byte count */ 	bsbb	xmit 	movl	r10,r2			/* starting block number */ 	bsbb	xmit 	movzwl	r8,r2			/* accumulated ckecksum */ 	bsbb	xmit  	/* collect read packet from device */ 	movl	r11,r0			/* starting addr */ 1: 	bsbb	recv2			/* get 2 packet characters */ 	decb	r2			/* data packet? */ 	bneq	1f			/* branch on end of data */ 	movzbl	r1,r8			/* get byte count of packet */  	/* read data into memory */ 2: 	bsbb	recv1			/* get a char */ 	movb	r1,(r0)+		/* stuff into memory */ 	sobgtr	r8,2b			/* loop if more */ 	bsbb	recv2			/* skip checksum */ 	brb	1b			/* read next packet */  	/* end of data xfer; check for errors */ 1: 	subl2	r6,r0			/* all bytes xfered? */ 	bneq	9f			/* nope, error */ 	bsbb	recv2			/* get success code */ 	tstl	r1			/* error in read? */ 	blss	9f			/* branch if status error */ 	movl	$5,r0 1: 	bsbb	recv2			/* discard 10 bytes */ 	sobgtr	r0,1b 	rsb  	/* fatal error */ 9: 	movab	ermsg,r1 1: 	movb	(r1)+,r0 	beql	bad 	bsbb	putc 	brb	1b  	/* update checksum in r8 and xmit 2 characters */ xmit: 	addw2	r2,r8			/* update checksum */ 	bcc	xmit2			/* branch if no overflow */ 	incw	r8			/* add  in carry */  	/* send the 2 characters contained in r2 */ xmit2: 	bsbb	1f			/* xmit one of '
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
comment|/* receive 2 characters, return in r2 and r1 */
name|recv2
range|:
name|bsbb
name|recv1
comment|/* recv one of 'em */
comment|/* fall into... */
comment|/* receive 1 character */
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
empty|#	blss	9b
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
name|movzbl
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
empty|#	movb	$0,r0
empty|#	bsbb	putc
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
name|movl
name|$0x400
decl_stmt|,
name|r6
comment|/* address of conversion table */
decl|1
range|:
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
decl|1b
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
name|addl2
name|r6
decl_stmt|,
name|r0
comment|/* calculate conversion table address */
name|movzbl
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
literal|"tu58 err\r\n"
name|end
operator|:
end_decl_stmt

end_unit

