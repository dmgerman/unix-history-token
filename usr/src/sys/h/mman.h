begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mman.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/* protections are chosen from these bits, or-ed together */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x1
end_define

begin_comment
comment|/* pages can be read */
end_comment

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x2
end_define

begin_comment
comment|/* pages can be written */
end_comment

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x4
end_define

begin_comment
comment|/* pages can be executed */
end_comment

begin_comment
comment|/* sharing types: choose either SHARED or PRIVATE */
end_comment

begin_define
define|#
directive|define
name|MAP_SHARED
value|1
end_define

begin_comment
comment|/* share changes */
end_comment

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|2
end_define

begin_comment
comment|/* changes are private */
end_comment

begin_comment
comment|/* advice to madvise */
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

