begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright.h */
end_comment

begin_comment
comment|/*  $RCSfile: copyright.h,v $  *  $Revision: 14020.12 $  *  $Date: 93/06/02 13:43:03 $  */
end_comment

begin_comment
comment|/*  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Copyright (c) 1992-1994 Mike Gleason, NCEMRSoft.  * Copyright (c) 1985, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions may not be sold for profit on physical  * media such as disks, tapes, and CD-ROMS, without expressed written  * permission.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_main_c_
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1992, 1993 by NCEMRSoft and Copyright (c) 1985, 1989 Regents of the University of California.\n All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _main_c_ */
end_comment

begin_comment
comment|/* eof copyright.h */
end_comment

end_unit

