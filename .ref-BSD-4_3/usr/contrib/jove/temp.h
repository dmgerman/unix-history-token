begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  * This program is copyright (C) 1985, 1986 by Jonathan Payne.  It is    *  * provided to you without charge for use only on a licensed Unix        *  * system.  You may copy JOVE provided that this notice is included with *  * the copy.  You may not sell copies of this program or versions        *  * modified for use on microcomputer systems, unless the copies are      *  * included with a Unix system distribution and the source is provided.  *  *************************************************************************/
end_comment

begin_comment
comment|/* This algorithm is just like the VI and ED ones.  There are several    differences though.  The first is that I don't just have THREE or TWO    incore blocks of the tmp file.  Instead there is a buffer cache of NBUF    buffers (64 on VM machines and the normal 3 on smaller ones).  Each block    is stored in LRU order and in a hash table by block #.  When a block is    requested it can quickly be looked up in the hash table.  If it's not    there the LRU block is used.  If it finds that the LRU block is dirty it    syncs the whole tmp file, i.e., does all the pending writes.  This works    really well on floppy disk systems, like the IBM PC, if the blocks are    sorted first.     The constants below are sorta hard to grok because they are in disguise,    but the basic idea is this:  The tmp file is allocated in chunks of    BNDRY/2 (or is it BNDRY? I can't remember) characters.  New lines are    added to the end of the tmp file.  The file is not garbage collected    because that would be too painful.  As a result, commands like Yank and    Kill are really easy.  Basically all we do is make copies of the disk    addresses of the lines.  It's fast--very.  So, putline(buf) writes BUF to    the disk and returns a new disk address.  Getline(addr, buf) is the    opposite of putline().  Lines do NOT cross block bounderies (as in VI and    ED) so that accessing the contents of lines can be much faster.  Pointers    to offsets into disk buffers are returned instead of copying the contents    into local arrays and then using them.  This cut down on the amount of    copying a great deal, at the expense of less efficiency.  But it's not a    big deal, really.  Incrementing the logical disk pointer by INCRMT is    like incrementing the physical disk pointer by a block.  The lower bit is    left alone, so JOVE uses that to mark lines as needing redisplay done to    them. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_if
if|#
directive|if
name|BUFSIZ
operator|==
literal|512
end_if

begin_define
define|#
directive|define
name|BLKMSK
value|01777
end_define

begin_define
define|#
directive|define
name|BNDRY
value|16
end_define

begin_define
define|#
directive|define
name|INCRMT
value|0100
end_define

begin_define
define|#
directive|define
name|LBTMSK
value|0760
end_define

begin_define
define|#
directive|define
name|NMBLKS
value|1018
end_define

begin_define
define|#
directive|define
name|OFFBTS
value|6
end_define

begin_define
define|#
directive|define
name|OFFMSK
value|077
end_define

begin_define
define|#
directive|define
name|SHFT
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLKMSK
value|0777
end_define

begin_define
define|#
directive|define
name|BNDRY
value|16
end_define

begin_define
define|#
directive|define
name|INCRMT
value|0200
end_define

begin_define
define|#
directive|define
name|LBTMSK
value|01760
end_define

begin_define
define|#
directive|define
name|NMBLKS
value|506
end_define

begin_define
define|#
directive|define
name|OFFBTS
value|7
end_define

begin_define
define|#
directive|define
name|OFFMSK
value|0177
end_define

begin_define
define|#
directive|define
name|SHFT
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLKMSK
value|077777
end_define

begin_define
define|#
directive|define
name|BNDRY
value|2
end_define

begin_define
define|#
directive|define
name|INCRMT
value|02000
end_define

begin_define
define|#
directive|define
name|LBTMSK
value|01776
end_define

begin_define
define|#
directive|define
name|NMBLKS
value|077770
end_define

begin_define
define|#
directive|define
name|OFFBTS
value|10
end_define

begin_define
define|#
directive|define
name|OFFMSK
value|01777
end_define

begin_define
define|#
directive|define
name|SHFT
value|0
end_define

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

begin_decl_stmt
specifier|extern
name|int
name|nleft
decl_stmt|,
comment|/* Number of good characters left in current block */
name|tmpfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|disk_line
name|tline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to end of tmp file */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tfname
decl_stmt|;
end_decl_stmt

end_unit

