begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	rlboot.c	4.2	83/02/20	*/
end_comment

begin_comment
comment|/*  * RL02 disk boot program to load "/boot" from  * a UNIX filesystem (starting at block 1 on pack on  * drive 0) into low core and to execute that file.  *  * This program can only read regular small 1k byte (3bsd+) files  * from the root of a UNIX filesystem.  *  * Hacked from a rk07 boot by Hank Trapnell, IMS.  *  *	/sys/mdec/hlboot.s	4.1	82/12/17  */
end_comment

begin_expr_stmt
operator|.
name|set
name|BLKSIZ
operator|,
literal|1024
comment|/* file system block size */
operator|.
name|set
name|BPSECT
operator|,
literal|256
comment|/* size of sector in bytes */
operator|.
name|set
name|RELOC
operator|,
literal|0x50000
operator|.
name|set
name|INOSIZ
operator|,
literal|64
comment|/* no. bytes/inode entry */
operator|.
name|set
name|INOBLK
operator|,
name|BLKSIZ
operator|/
name|INOSIZ
comment|/* no. inodes/disc block */
operator|.
name|set
name|INOMSK
operator|,
literal|0xfffffff0
comment|/* changes with inode size */
operator|.
name|set
name|NAMSIZ
operator|,
literal|14
comment|/* bytes in directory name */
operator|.
name|set
name|ENTADR
operator|,
literal|024
comment|/* offset to entry addr in a.out */
operator|.
name|set
name|DIRSIZ
operator|,
literal|16
comment|/* size of directory entry, bytes */
operator|.
name|set
name|ROOTINO
operator|,
literal|2
comment|/* root dir inode no. */
operator|.
name|set
name|NBOO
operator|,
literal|1
comment|/* no. of boot blocks */
operator|.
name|set
name|NSUP
operator|,
literal|1
comment|/* no. of superblocks */
operator|.
name|set
name|SID
operator|,
literal|62
comment|/* system ID register */
comment|/* UBA registers */
operator|.
name|set
name|UBA_CNFGR
operator|,
literal|0
comment|/* UBA configuration register */
operator|.
name|set
name|UBA_CR
operator|,
literal|4
comment|/* UBA control register offset */
operator|.
name|set
name|UBA_MAP
operator|,
literal|0x800
comment|/* UBA offset to map reg's */
operator|.
name|set
name|UBAinit
operator|,
literal|1
comment|/* UBA init bit in UBA control reg */
operator|.
name|set
name|pUBIC
operator|,
literal|16
comment|/* Unibus init complete */
comment|/* RL11 registers and bits */
operator|.
name|set
name|HL
operator|,
literal|0174400
operator|-
literal|0160000
comment|/* address of RL11 */
operator|.
name|set
name|HL_cs
operator|,
name|HL
operator|+
literal|0
comment|/* control and status */
operator|.
name|set
name|HL_ba
operator|,
name|HL
operator|+
literal|2
comment|/* bus address */
operator|.
name|set
name|HL_da
operator|,
name|HL
operator|+
literal|4
comment|/* disk address */
operator|.
name|set
name|HL_mp
operator|,
name|HL
operator|+
literal|6
comment|/* word count */
operator|.
name|set
name|HLSECT
operator|,
literal|40
comment|/* sectors per track */
operator|.
name|set
name|HLTRAC
operator|,
literal|2
comment|/* tracks per cylinder */
operator|.
name|set
name|HLST
operator|,
name|HLSECT
operator|*
name|HLTRAC
operator|.
name|set
name|HL_GO
operator|,
literal|0
comment|/* go bit */
operator|.
name|set
name|HL_RCOM
operator|,
literal|014
comment|/* read command */
operator|.
name|set
name|HL_SEEK
operator|,
literal|06
comment|/* seek */
operator|.
name|set
name|HL_GSTAT
operator|,
literal|04
comment|/* get status command */
operator|.
name|set
name|HL_RHDR
operator|,
literal|010
comment|/* read header */
operator|.
name|set
name|HL_RESET
operator|,
literal|013
comment|/* reset drive */
operator|.
name|set
name|HL_HS
operator|,
literal|020
comment|/* head select */
operator|.
name|set
name|HL_DIR
operator|,
literal|04
comment|/* seek direction */
operator|.
name|set
name|HL_pRDY
operator|,
literal|7
comment|/* position of ready bit */
operator|.
name|set
name|HL_pERR
operator|,
literal|15
comment|/* position of error bit */
name|init
operator|:
comment|/* r9   UBA address */
comment|/* r10  umem addr */
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
comment|/* some no-ops for 750 boot to skip */
name|nop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nop
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* get cpu type and find the first uba */
end_comment

begin_decl_stmt
name|mfpr
name|$SID
decl_stmt|,
name|r0
name|extzv
name|$24
decl_stmt|,
name|$8
decl_stmt|,
name|r0
decl_stmt|,
name|r0
comment|/* get cpu type */
name|ashl
name|$2
decl_stmt|,
name|r0
decl_stmt|,
name|r1
name|movab
name|physUBA
decl_stmt|,
name|r2
comment|/* get physUBA[cpu] */
name|addl2
name|r1
decl_stmt|,
name|r2
name|movl
argument_list|(
name|r2
argument_list|)
decl_stmt|,
name|r9
name|movab
name|physUMEM
decl_stmt|,
name|r2
comment|/* get physUMEM[cpu] */
name|addl2
name|r1
decl_stmt|,
name|r2
name|movl
argument_list|(
name|r2
argument_list|)
decl_stmt|,
name|r10
comment|/* if 780, init uba */
name|cmpl
name|r0
decl_stmt|,
name|$1
name|bneq
decl|2f
name|movl
name|$UBAinit
decl_stmt|,
name|UBA_CR
argument_list|(
name|r9
argument_list|)
decl|1
range|:
name|bbc
name|$pUBIC
decl_stmt|,
name|UBA_CNFGR
argument_list|(
name|r9
argument_list|)
decl_stmt|,1b 2
range|:
comment|/* init rl11, and drive 0, don't check for any errors now */
name|movw
name|$HL_RESET
decl_stmt|,
name|HL_da
argument_list|(
name|r10
argument_list|)
name|movw
name|$HL_GSTAT
decl|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
comment|/* relocate to high core */
name|start
range|:
name|movl
name|r5
decl_stmt|,
name|r11
comment|/* boot flags */
name|movl
name|$RELOC
decl_stmt|,
name|sp
name|moval
name|init
decl_stmt|,
name|r6
name|movc3
name|$end
decl_stmt|,
argument_list|(
name|r6
argument_list|)
decl_stmt|,
argument_list|(
name|sp
argument_list|)
name|jmp
modifier|*
name|$RELOC
decl|+
name|start2
comment|/* now running relocated */
comment|/* search for ``boot'' in root inode */
name|start2
range|:
name|movl
name|$names
operator|+
name|RELOC
decl_stmt|,
name|r6
name|movzbl
name|$ROOTINO
decl_stmt|,
name|r0
name|nxti
range|:
name|clrw
operator|*
name|$bno
comment|/* start with first block in inode */
name|bsbw
name|iget
name|tstb
argument_list|(
argument|r6
argument_list|)
name|beql
name|getfil
comment|/* found correct inode! */
name|get1b
operator|:
name|bsbw
name|rmblk
comment|/* read inode from block now in memory */
name|beql
name|start2
name|movl
name|$buf
decl_stmt|,
name|r7
name|nxtent
range|:
name|tstw
argument_list|(
argument|r7
argument_list|)
name|beql
name|dirchk
name|cmpc3
name|$NAMSIZ
decl_stmt|,
argument_list|(
name|r6
argument_list|)
decl_stmt|,2
argument_list|(
name|r7
argument_list|)
name|bneq
name|dirchk
name|movzwl
argument_list|(
name|r7
argument_list|)
decl_stmt|,
name|r0
name|addl2
name|$NAMSIZ
decl_stmt|,
name|r6
name|brb
name|nxti
name|dirchk
range|:
name|acbl
name|$buf
operator|+
name|BLKSIZ
operator|-
literal|1
decl_stmt|,
name|$DIRSIZ
decl_stmt|,
name|r7
decl_stmt|,
name|nxtent
name|brb
name|get1b
comment|/* found inode for desired file... read it in */
name|getfil
range|:
name|clrl
name|bufptr
name|getlop
operator|:
name|bsbb
name|rmblk
name|beql
name|clear
name|addl2
name|$BLKSIZ
decl_stmt|,
name|bufptr
name|brb
name|getlop
name|clear
range|:
name|movl
operator|*
name|$size
decl_stmt|,
name|r3
name|clrcor
range|:
name|clrq
argument_list|(
argument|r3
argument_list|)
name|acbl
name|$RELOC
decl_stmt|,
name|$8
decl_stmt|,
name|r3
decl_stmt|,
name|clrcor
comment|/* run loaded program */
name|movl
name|$8
decl_stmt|,
name|r10
comment|/* major("/dev/hl0a") */
name|calls
name|$0
decl_stmt|,
modifier|*
name|$0
name|brw
name|start2
comment|/* iget: get inode block whose # is in r0 */
name|iget
range|:
name|addl3
name|$
argument_list|(
name|INOBLK
operator|*
operator|(
name|NBOO
operator|+
name|NSUP
operator|)
argument_list|)
operator|-
literal|1
decl_stmt|,
name|r0
decl_stmt|,
name|r8
name|divl3
name|$INOBLK
decl_stmt|,
name|r8
decl_stmt|,
name|r4
name|bsbw
name|rblk
name|bicl2
name|$INOMSK
decl_stmt|,
name|r8
name|mull2
name|$INOSIZ
decl_stmt|,
name|r8
name|addl2
name|$buf
decl_stmt|,
name|r8
name|movc3
name|$time
decl|-
name|inode
decl_stmt|,
argument_list|(
name|r8
argument_list|)
decl_stmt|,
modifier|*
name|$inode
name|rsb
comment|/* rmblk: read in bno into addr */
name|rmblk
range|:
name|movzwl
operator|*
name|$bno
decl_stmt|,
name|r0
name|addw2
name|$3
decl_stmt|,
modifier|*
name|$bno
name|addl2
name|$addr
decl_stmt|,
name|r0
comment|/* this boot assumes only small files (<=10k bytes, ie. no indirect blocks) */
name|extzv
name|$0
decl_stmt|,
name|$24
decl_stmt|,
argument_list|(
name|r0
argument_list|)
decl_stmt|,
name|r4
name|bneq
name|rblk
name|rsb
comment|/* rblk: read disk block whose number is in r4 */
name|rblk
range|:
name|movzbw
name|$HL_RHDR
operator|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
name|bsbw
name|hlwait
name|movzwl
name|HL_mp
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|extzv
name|$7
decl_stmt|,
name|$9
decl_stmt|,
name|r0
decl_stmt|,
name|r3
comment|/* get current cylinder */
name|mull2
name|$BLKSIZ
decl|/
name|BPSECT
decl_stmt|,
name|r4
name|clrl
name|r5
name|ediv
name|$HLST
decl_stmt|,
name|r4
decl_stmt|,
name|r0
decl_stmt|,
name|r1
comment|/* get desired cylinder */
name|movzbl
name|$1
decl_stmt|,
name|r5
name|subl2
name|r0
decl_stmt|,
name|r3
name|bgeq
decl|1f
name|mnegl
name|r3
decl_stmt|,
name|r3
name|bisl2
name|$HL_DIR
decl_stmt|,
name|r5
comment|/* move towards the spindle */
decl|1
range|:
name|insv
name|r3
decl_stmt|,
name|$7
decl_stmt|,
name|$9
decl_stmt|,
name|r5
name|clrl
name|r2
name|ediv
name|$HLSECT
decl_stmt|,
name|r1
decl_stmt|,
name|r2
decl_stmt|,
name|r1
name|tstl
name|r2
name|beql
decl|1f
name|bisl2
name|$HL_HS
decl_stmt|,
name|r5
decl|1
range|:
name|movl
name|r5
decl_stmt|,
name|HL_da
argument_list|(
name|r10
argument_list|)
name|ashl
name|$7
decl_stmt|,
name|r0
decl_stmt|,
name|r5
name|movw
name|$HL_SEEK
decl|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
name|bsbb
name|hlwait
name|tstl
name|r2
name|beql
decl|1f
name|bisl2
name|$0x40
decl_stmt|,
name|r5
decl|1
range|:
name|addl2
name|r1
decl_stmt|,
name|r5
name|ashl
name|$
decl|-9
decl_stmt|,
name|bufptr
decl_stmt|,
name|r0
name|bisl3
name|$0x80000000
decl_stmt|,
name|r0
decl_stmt|,
name|UBA_MAP
argument_list|(
name|r9
argument_list|)
name|incl
name|r0
name|bisl3
name|$0x80000000
decl_stmt|,
name|r0
decl_stmt|,
name|UBA_MAP
decl|+4
argument_list|(
name|r9
argument_list|)
name|clrw
name|HL_ba
argument_list|(
name|r10
argument_list|)
name|movw
name|r5
decl_stmt|,
name|HL_da
argument_list|(
name|r10
argument_list|)
name|movw
name|$
decl|-
name|BLKSIZ
decl|/2
decl_stmt|,
name|HL_mp
argument_list|(
name|r10
argument_list|)
name|movw
name|$HL_RCOM
decl|+
name|HL_GO
decl_stmt|,
name|HL_cs
argument_list|(
name|r10
argument_list|)
name|hlwait
range|:
comment|/* wait for controller ready */
name|movw
name|HL_cs
argument_list|(
name|r10
argument_list|)
decl_stmt|,
name|r0
name|bbc
name|$HL_pRDY
decl_stmt|,
name|r0
decl_stmt|,
name|hlwait
name|bbs
name|$HL_pERR
decl_stmt|,
name|r0
decl_stmt|,
name|hlerr
name|bicpsw
name|$2
name|rsb
name|hlerr
range|:
name|halt
comment|/* ungraceful */
name|bufptr
operator|:
operator|.
name|long
name|buf
name|names
operator|:
operator|.
name|byte
literal|'b,'
name|o
decl_stmt|,'o,'
name|t
decl_stmt|,0,0,0,0,0,0,0,0,0,0         .
name|byte
decl|0
name|physUBA
range|:
operator|.
name|long
literal|0
operator|.
name|long
literal|0x20006000
comment|/* 11/780 */
operator|.
name|long
literal|0xf30000
comment|/* 11/750 */
operator|.
name|long
literal|0xf26000
comment|/* 11/7ZZ */
name|physUMEM
operator|:
operator|.
name|long
literal|0
operator|.
name|long
literal|0x2013e000
comment|/* 11/780 */
operator|.
name|long
literal|0xffe000
comment|/* 11/750 */
operator|.
name|long
literal|0xffe000
comment|/* 11/7ZZ */
name|end
operator|:
operator|.
name|set
name|buf
decl_stmt|,
name|RELOC
decl|-1536         .
name|set
name|inode
decl_stmt|,
name|RELOC
decl|-512         .
name|set
name|mode
decl_stmt|,
name|inode
operator|.
name|set
name|nlink
decl_stmt|,
name|mode
decl|+2         .
name|set
name|uid
decl_stmt|,
name|nlink
decl|+2         .
name|set
name|gid
decl_stmt|,
name|uid
decl|+2         .
name|set
name|size
decl_stmt|,
name|gid
decl|+2         .
name|set
name|addr
decl_stmt|,
name|size
decl|+4         .
name|set
name|time
decl_stmt|,
name|addr
decl|+40         .
name|set
name|bno
decl_stmt|,
name|time
decl|+12
end_decl_stmt

end_unit

