begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tuboot.c	4.1	83/02/16	*/
end_comment

begin_comment
comment|/*  * VAX tu58 console cassette boot block  *  * Thomas Ferrin  27oct82  *  * Reads a program from a tp directory on tape  * and executes it.  Program must be stripped of  * the header and is loaded ``bits as is''.  * You can return to this loader via ``ret'' as  * you are called ``calls $0,ent''.  */
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
comment|/*	.set	DIRBLK,8	/* tp directory starts at block 8 */
operator|.
name|set
name|DIRBLK
operator|,
literal|1
comment|/* tp directory starts at block 1 */
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
name|tapa
operator|,
operator|-
literal|4
comment|/* desired tape addr */
operator|.
name|set
name|name
operator|,
operator|-
literal|8
operator|-
name|PTHSIZ
comment|/* operator-typed file name */
comment|/* ===== */
comment|/* initialization */
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
comment|/* dumb operator */
name|clrb
argument_list|(
name|r1
argument_list|)
decl|+
name|incl
name|r9
comment|/* user-specified tp filename has been stored at name(fp) */
comment|/* read in entire tp directory contents into low core */
name|dirred
range|:
name|movl
name|$DIRBLK
decl_stmt|,
name|tapa
argument_list|(
name|fp
argument_list|)
comment|/* tp directory starts at block DIRBLK */
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
name|bsbw
name|taper
comment|/* read no. bytes indicated */
comment|/* search entire directory for user-specified file name */
name|clrl
name|r5
comment|/* dir buff loc = 0 */
name|nxtdir
range|:
name|cmpc3
name|r9
decl_stmt|,
argument_list|(
name|r5
argument_list|)
decl_stmt|,
argument_list|(
name|r4
argument_list|)
comment|/* see if dir entry matches filename */
name|beql
name|fndfil
comment|/* found match */
name|acbl
name|$NUMDIR
modifier|*
name|BLKSIZ
decl|-1
decl_stmt|,
name|$ENTSIZ
decl_stmt|,
name|r5
decl_stmt|,
name|nxtdir
comment|/* see if done with tp dir */
name|brw
name|start
comment|/* entry not in directory; start over */
comment|/* found desired tp dir entry */
name|fndfil
range|:
name|movzwl
name|BNUM
argument_list|(
name|r5
argument_list|)
decl_stmt|,
name|tapa
argument_list|(
name|fp
argument_list|)
comment|/* start block no., 2 bytes */
name|addl2
name|$DIRBLK
decl|-1
decl_stmt|,
name|tapa
argument_list|(
name|fp
argument_list|)
comment|/* skip boot block(s) */
name|movzwl
name|FILSIZ
argument_list|(
name|r5
argument_list|)
decl_stmt|,
name|r6
comment|/* low 2 bytes file size */
name|insv
name|FILSIZ
decl|-1
argument_list|(
name|r5
argument_list|)
decl_stmt|,
name|$16
decl_stmt|,
name|$8
decl_stmt|,
name|r6
comment|/* file size, high byte */
name|cmpl
name|r6
decl_stmt|,
name|$RELOC
decl|-512
comment|/* check if file fits below stack */
name|blss
name|filok
comment|/* file o.k. */
name|brw
name|start
comment|/* file too large */
comment|/* time to read in desired file from tape */
name|filok
range|:
name|movl
name|r6
decl_stmt|,
name|r5
comment|/* start of bss space */
name|bsbb
name|taper
name|bsbb
name|rew
comment|/* clear core */
name|subl3
name|r5
decl_stmt|,
name|$RELOC
decl|-4
decl_stmt|,
name|r0
comment|/* no. bytes to clear */
decl|1
range|:
name|clrb
argument_list|(
name|r5
argument_list|)
operator|+
name|sobgtr
name|r0
decl_stmt|,1b
comment|/* time to jump to start of file& execute */
name|addl3
name|$20
decl_stmt|,
name|fp
decl_stmt|,
name|ap
name|clrl
name|r5
name|calls
name|$0
decl_stmt|,
argument_list|(
name|r5
argument_list|)
name|bad
range|:
name|brw
name|start
comment|/* rewind tape */
name|rew
operator|:
name|movb
name|$5
decl_stmt|,
name|readcom
decl|+2
comment|/* position opcode */
name|clrl
name|tapa
argument_list|(
name|fp
argument_list|)
comment|/* block 0 */
name|clrl
name|r6
comment|/* 0 bytes */
name|bsbb
name|taper
name|movb
name|$2
decl_stmt|,
name|readcom
decl|+2
comment|/* read opcode */
name|rsb
comment|/* read (r6) bytes from tapa(fp) into loc 0 */
name|taper
range|:
name|clrl
name|r8
comment|/* initialize checksum */
name|movab
name|readcom
decl_stmt|,
name|r0
comment|/* read command packet addr */
name|movzbl
name|$TU_PACKETLEN
decl|/2
decl_stmt|,
name|r1
comment|/* size of readcom block */
decl|1
range|:
name|movzwl
argument_list|(
name|r0
argument_list|)
operator|+
decl_stmt|,
name|r2
comment|/* get 2 chars from block */
name|bsbb
name|xmit
comment|/* xmit and update ckecksum */
name|sobgtr
name|r1
decl_stmt|,1b
comment|/* loop if more */
comment|/* now do variable part of packet */
name|movl
name|r6
decl_stmt|,
name|r2
comment|/* byte count */
name|bsbb
name|xmit
name|movzwl
name|tapa
argument_list|(
name|fp
argument_list|)
decl_stmt|,
name|r2
comment|/* starting block number */
name|bsbb
name|xmit
name|movzwl
name|r8
decl_stmt|,
name|r2
comment|/* accumulated ckecksum */
name|bsbb
name|xmit
comment|/* collect read packet from device */
name|clrl
name|r0
comment|/* starting addr */
decl|1
range|:
name|bsbb
name|recv2
comment|/* get 2 packet characters */
name|decb
name|r2
comment|/* data packet? */
name|bneq
literal|1f
comment|/* branch on end of data */
name|movzbl
name|r1
decl_stmt|,
name|r8
comment|/* get byte count of packet */
comment|/* read data into memory */
decl|2
range|:
name|bsbb
name|recv1
comment|/* get a char */
name|movb
name|r1
decl_stmt|,
argument_list|(
name|r0
argument_list|)
decl_stmt|+
comment|/* stuff into memory */
name|sobgtr
name|r8
decl_stmt|,2b
comment|/* loop if more */
name|bsbb
name|recv2
comment|/* skip checksum */
name|brb
decl|1b
comment|/* read next packet */
comment|/* end of data xfer; check for errors */
decl|1
range|:
name|subl2
name|r6
decl_stmt|,
name|r0
comment|/* all bytes xfered? */
name|bneq
decl|9f
comment|/* nope, error */
name|bsbb
name|recv2
comment|/* get success code */
name|tstl
name|r1
comment|/* error in read? */
name|blss
decl|9f
comment|/* branch if status error */
name|movl
name|$5
decl_stmt|,
name|r0
decl|1
range|:
name|bsbb
name|recv2
comment|/* discard 10 bytes */
name|sobgtr
name|r0
decl_stmt|,1b
name|rsb
comment|/* fatal error */
decl|9
range|:
name|movab
name|ermsg
decl_stmt|,
name|r1
decl|1
range|:
name|movb
argument_list|(
name|r1
argument_list|)
operator|+
decl_stmt|,
name|r0
name|beql
name|bad
name|bsbb
name|putc
name|brb
decl|1b
comment|/* update checksum in r8 and xmit 2 characters */
name|xmit
range|:
name|addw2
name|r2
decl_stmt|,
name|r8
comment|/* update checksum */
name|bcc
name|xmit2
comment|/* branch if no overflow */
name|incw
name|r8
comment|/* add  in carry */
comment|/* send the 2 characters contained in r2 */
name|xmit2
range|:
name|bsbb
literal|1f
comment|/* xmit one of 'em */
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
name|movb
name|$0
decl_stmt|,
name|r0
name|bsbb
name|putc
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
name|extzv
name|$0
decl_stmt|,
name|$7
decl_stmt|,
name|r0
decl_stmt|,
name|r0
name|mtpr
name|r0
decl_stmt|,
name|$TXDB
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

