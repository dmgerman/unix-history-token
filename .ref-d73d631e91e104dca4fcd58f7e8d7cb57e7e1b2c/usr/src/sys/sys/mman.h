begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * %sccs.include.redist.c%  *  *	@(#)mman.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Protections are chosen from these bits, or-ed together  */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x04
end_define

begin_comment
comment|/* pages can be read */
end_comment

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x02
end_define

begin_comment
comment|/* pages can be written */
end_comment

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x01
end_define

begin_comment
comment|/* pages can be executed */
end_comment

begin_comment
comment|/*  * Flags contain mapping type, sharing type and options.  * Mapping type; choose one  */
end_comment

begin_define
define|#
directive|define
name|MAP_FILE
value|0x0001
end_define

begin_comment
comment|/* mapped from a file or device */
end_comment

begin_define
define|#
directive|define
name|MAP_ANON
value|0x0002
end_define

begin_comment
comment|/* allocated from memory, swap space */
end_comment

begin_define
define|#
directive|define
name|MAP_TYPE
value|0x000f
end_define

begin_comment
comment|/* mask for type field */
end_comment

begin_comment
comment|/*  * Sharing types; choose one  */
end_comment

begin_define
define|#
directive|define
name|MAP_COPY
value|0x0020
end_define

begin_comment
comment|/* "copy" region at mmap time */
end_comment

begin_define
define|#
directive|define
name|MAP_SHARED
value|0x0010
end_define

begin_comment
comment|/* share changes */
end_comment

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0x0000
end_define

begin_comment
comment|/* changes are private */
end_comment

begin_comment
comment|/*  * Other flags  */
end_comment

begin_define
define|#
directive|define
name|MAP_FIXED
value|0x0100
end_define

begin_comment
comment|/* map addr must be exactly as requested */
end_comment

begin_define
define|#
directive|define
name|MAP_NOEXTEND
value|0x0200
end_define

begin_comment
comment|/* for MAP_FILE, don't change file size */
end_comment

begin_define
define|#
directive|define
name|MAP_HASSEMPHORE
value|0x0400
end_define

begin_comment
comment|/* region may contain semaphores */
end_comment

begin_define
define|#
directive|define
name|MAP_INHERIT
value|0x0800
end_define

begin_comment
comment|/* region is retained after exec */
end_comment

begin_comment
comment|/*  * Advice to madvise  */
end_comment

begin_define
define|#
directive|define
name|MADV_NORMAL
value|0
end_define

begin_comment
comment|/* no further special treatment */
end_comment

begin_define
define|#
directive|define
name|MADV_RANDOM
value|1
end_define

begin_comment
comment|/* expect random page references */
end_comment

begin_define
define|#
directive|define
name|MADV_SEQUENTIAL
value|2
end_define

begin_comment
comment|/* expect sequential page references */
end_comment

begin_define
define|#
directive|define
name|MADV_WILLNEED
value|3
end_define

begin_comment
comment|/* will need these pages */
end_comment

begin_define
define|#
directive|define
name|MADV_DONTNEED
value|4
end_define

begin_comment
comment|/* dont need these pages */
end_comment

end_unit

