begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ex_temp.h	7.4 (Berkeley) 5/31/85  */
end_comment

begin_comment
comment|/*  * The editor uses a temporary file for files being edited, in a structure  * similar to that of ed.  The first block of the file is used for a header  * block which guides recovery after editor/system crashes.  * Lines are represented in core by a pointer into the temporary file which  * is packed into 16 bits (32 on VMUNIX).  All but the low bit index the temp  * file; the last is used by global commands.  The parameters below control  * how much the other bits are shifted left before they index the temp file.  * Larger shifts give more slop in the temp file but allow larger files  * to be edited.  *  * The editor does not garbage collect the temporary file.  When a new  * file is edited, the temporary file is rather discarded and a new one  * created for the new file.  Garbage collection would be rather complicated  * in ex because of the general undo, and in any case would require more  * work when throwing lines away because marks would have be carefully  * checked before reallocating temporary file space.  Said another way,  * each time you create a new line in the temporary file you get a unique  * number back, and this is a property used by marks.  *  * The following temp file parameters allow 256k bytes in the temporary  * file.  By changing to the numbers in comments you can get 512k.  * For VMUNIX you get more than you could ever want.  * VMUNIX uses long (32 bit) integers giving much more  * space in the temp file and no waste.  This doubles core  * requirements but allows files of essentially unlimited size to be edited.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|BLKMSK
value|0777
end_define

begin_comment
comment|/* 01777 */
end_comment

begin_define
define|#
directive|define
name|BNDRY
value|8
end_define

begin_comment
comment|/* 16 */
end_comment

begin_define
define|#
directive|define
name|INCRMT
value|0200
end_define

begin_comment
comment|/* 0100 */
end_comment

begin_define
define|#
directive|define
name|LBTMSK
value|0770
end_define

begin_comment
comment|/* 0760 */
end_comment

begin_define
define|#
directive|define
name|NMBLKS
value|506
end_define

begin_comment
comment|/* 1018 */
end_comment

begin_define
define|#
directive|define
name|OFFBTS
value|7
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|OFFMSK
value|0177
end_define

begin_comment
comment|/* 077 */
end_comment

begin_define
define|#
directive|define
name|SHFT
value|2
end_define

begin_comment
comment|/* 3 */
end_comment

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
end_endif

begin_comment
comment|/*  * The editor uses three buffers into the temporary file (ed uses two  * and is very similar).  These are two read buffers and one write buffer.  * Basically, the editor deals with the file as a sequence of BUFSIZ character  * blocks.  Each block contains some number of lines (and lines  * can run across block boundaries.  *  * New lines are written into the last block in the temporary file  * which is in core as obuf.  When a line is needed which isn't in obuf,  * then it is brought into an input buffer.  As there are two, the choice  * is to take the buffer into which the last read (of the two) didn't go.  * Thus this is a 2 buffer LRU replacement strategy.  Measurement  * shows that this saves roughly 25% of the buffer reads over a one  * input buffer strategy.  Since the editor (on our VAX over 1 week)  * spends (spent) roughly 30% of its time in the system read routine,  * this can be a big help.  */
end_comment

begin_decl_stmt
name|var
name|bool
name|hitin2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last read hit was ibuff2 not ibuff */
end_comment

begin_decl_stmt
name|var
name|bool
name|ichang2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have actually changed ibuff2 */
end_comment

begin_decl_stmt
name|var
name|bool
name|ichanged
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have actually changed ibuff */
end_comment

begin_decl_stmt
name|var
name|short
name|iblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp file block number of ibuff (or -1) */
end_comment

begin_decl_stmt
name|var
name|short
name|iblock2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp file block number of ibuff2 (or -1) */
end_comment

begin_decl_stmt
name|var
name|short
name|ninbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number useful chars left in input buffer */
end_comment

begin_decl_stmt
name|var
name|short
name|nleft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number usable chars left in output buffer */
end_comment

begin_decl_stmt
name|var
name|short
name|oblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp file block number of obuff (or -1) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_decl_stmt
name|var
name|short
name|tline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current temp file ptr */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|var
name|int
name|tline
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|var
name|char
name|ibuff
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
name|ibuff2
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|var
name|char
name|obuff
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure of the descriptor block which resides  * in the first block of the temporary file and is  * the guiding light for crash recovery.  *  * As the Blocks field below implies, there are temporary file blocks  * devoted to (some) image of the incore array of pointers into the temp  * file.  Thus, to recover from a crash we use these indices to get the  * line pointers back, and then use the line pointers to get the text back.  * Except for possible lost lines due to sandbagged I/O, the entire  * file (at the time of the last editor "sync") can be recovered from  * the temp file.  */
end_comment

begin_comment
comment|/* This definition also appears in expreserve.c... beware */
end_comment

begin_struct
struct|struct
name|header
block|{
name|time_t
name|Time
decl_stmt|;
comment|/* Time temp file last updated */
name|int
name|Uid
decl_stmt|;
ifndef|#
directive|ifndef
name|VMUNIX
name|short
name|Flines
decl_stmt|;
comment|/* Number of lines in file */
else|#
directive|else
name|int
name|Flines
decl_stmt|;
endif|#
directive|endif
name|char
name|Savedfile
index|[
name|FNSIZE
index|]
decl_stmt|;
comment|/* The current file name */
name|short
name|Blocks
index|[
name|LBLKS
index|]
decl_stmt|;
comment|/* Blocks where line pointers stashed */
block|}
struct|;
end_struct

begin_decl_stmt
name|var
name|struct
name|header
name|H
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|uid
value|H.Uid
end_define

begin_define
define|#
directive|define
name|flines
value|H.Flines
end_define

begin_define
define|#
directive|define
name|savedfile
value|H.Savedfile
end_define

begin_define
define|#
directive|define
name|blocks
value|H.Blocks
end_define

end_unit

