begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* The tmp file is indexed in chunks of CH_SIZE characters.  CH_SIZE is    (1<< CH_BITS).  New lines are added to the end of the tmp file.  The    file is not garbage collected because that would be too painful.  As a    result, commands like Yank and Kill are really easy; basically all we    do is make copies of the disk addresses of the lines (as opposed to    the contents).  So, putline(buf) writes BUF to the disk and returns a    new disk address.  Getline(addr, buf) is the opposite of putline().    f_getputl(line, fp) reads from open FP directly into the tmp file (into    the buffer cache (see below)) and stores the address in LINE.  This is    used during read_file to minimize compying.     Lines do NOT cross block bounderies in the tmp file so that accessing    the contents of lines can be much faster.  Pointers to offsets into    disk buffers are returned instead of copying the contents into local    arrays and then using them.  This cuts down on the amount of copying a    great deal, at the expense of less efficiency.  The lower bit of disk    addresses is used for marking lines as needing redisplay done.     There is a buffer cache of NBUF buffers (64 on !SMALL machines and the    3 on small ones).  The blocks are stored in LRU order and each block    is also stored in a hash table by block #.  When a block is requested    it can quickly be looked up in the hash table.  If it's not there the    LRU block is assigned the new block #.  If it finds that the LRU block    is dirty (i.e., has pending IO) it syncs the WHOLE tmp file, i.e.,    does all the pending writes.  This works much better on floppy disk    systems, like the IBM PC, if the blocks are sorted before sync'ing. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL
end_ifdef

begin_define
define|#
directive|define
name|CH_BITS
value|4
end_define

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
name|MAX_BLOCKS
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAX_BLOCKS
value|512
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
name|CH_BITS
value|0
end_define

begin_define
define|#
directive|define
name|MAX_BLOCKS
value|4096
end_define

begin_comment
comment|/* basically unlimited */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMALL */
end_comment

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
name|BNO_SHIFT
value|(9 - CH_BITS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BNO_SHIFT
value|(10 - CH_BITS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CH_SIZE is how big each chunk is.  For each 1 the DFree pointer    is incremented we extend the tmp file by CH_SIZE characters.    CH_PBLOCK is the # of chunks per block.  RND_MASK is used to mask    off the lower order bits of the daddr to round down to the beginning    of a block.  OFF_MASK masks off the higher order bits so we can get    at the offset into the disk buffer.     NOTE:  It's pretty important that these numbers be multiples of 	  2.  Be careful if you change things. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_define
define|#
directive|define
name|CH_SIZE
value|(1<< CH_BITS)
end_define

begin_define
define|#
directive|define
name|CH_PBLOCK
value|(BUFSIZ / CH_SIZE)
end_define

begin_define
define|#
directive|define
name|RND_MASK
value|(CH_PBLOCK - 1)
end_define

begin_define
define|#
directive|define
name|OFF_MASK
value|(BUFSIZ - 1)
end_define

begin_define
define|#
directive|define
name|BNO_MASK
value|(MAX_BLOCKS - 1)
end_define

begin_define
define|#
directive|define
name|blk_round
parameter_list|(
name|daddr
parameter_list|)
value|(daddr& ~RND_MASK)
end_define

begin_define
define|#
directive|define
name|forward_block
parameter_list|(
name|daddr
parameter_list|)
value|(daddr + CH_PBLOCK)
end_define

begin_define
define|#
directive|define
name|da_to_bno
parameter_list|(
name|daddr
parameter_list|)
value|((daddr>> BNO_SHIFT)& BNO_MASK)
end_define

begin_define
define|#
directive|define
name|da_to_off
parameter_list|(
name|daddr
parameter_list|)
value|((daddr<< CH_BITS)& OFF_MASK)
end_define

begin_define
define|#
directive|define
name|da_too_huge
parameter_list|(
name|daddr
parameter_list|)
value|((daddr>> BNO_SHIFT)>= MAX_BLOCKS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CH_SIZE
value|((disk_line)1<< CH_BITS)
end_define

begin_define
define|#
directive|define
name|CH_PBLOCK
value|((disk_line)BUFSIZ / CH_SIZE)
end_define

begin_define
define|#
directive|define
name|RND_MASK
value|((disk_line)CH_PBLOCK - 1)
end_define

begin_define
define|#
directive|define
name|OFF_MASK
value|((disk_line)BUFSIZ - 1)
end_define

begin_define
define|#
directive|define
name|BNO_MASK
value|((disk_line)MAX_BLOCKS - 1)
end_define

begin_define
define|#
directive|define
name|blk_round
parameter_list|(
name|daddr
parameter_list|)
value|((disk_line)daddr& ~RND_MASK)
end_define

begin_define
define|#
directive|define
name|forward_block
parameter_list|(
name|daddr
parameter_list|)
value|((disk_line)daddr + CH_PBLOCK)
end_define

begin_define
define|#
directive|define
name|da_to_bno
parameter_list|(
name|daddr
parameter_list|)
value|((disk_line)(daddr>> BNO_SHIFT)& BNO_MASK)
end_define

begin_define
define|#
directive|define
name|da_to_off
parameter_list|(
name|daddr
parameter_list|)
value|((disk_line)(daddr<< CH_BITS)& OFF_MASK)
end_define

begin_define
define|#
directive|define
name|da_too_huge
parameter_list|(
name|daddr
parameter_list|)
value|((disk_line)(daddr>> BNO_SHIFT)>= MAX_BLOCKS)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

