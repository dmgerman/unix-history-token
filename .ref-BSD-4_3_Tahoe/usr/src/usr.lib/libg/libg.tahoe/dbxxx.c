begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_label
name|_sccsid
label|:
end_label

begin_expr_stmt
operator|.
name|asciz
literal|"@(#)dbxxx.c	5.3 (Berkeley) 1/26/86"
endif|#
directive|endif
endif|not lint
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
define|#
directive|define
name|CALL
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|callg	n,*f
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|tahoe
argument_list|)
define|#
directive|define
name|CALL
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|calls	n,*f
endif|#
directive|endif
operator|.
name|data
operator|.
name|comm
name|__dbargs
operator|,
literal|512
operator|.
name|text
operator|.
name|align
literal|1
operator|.
name|globl
name|__dsubc
name|__dsubc
operator|:
name|CALL
argument_list|(
name|__dbargs
operator|+
literal|4
argument_list|,
name|__dbargs
argument_list|)
operator|.
name|globl
name|__dsubn
name|__dsubn
operator|:
name|halt
operator|.
name|data
comment|/*  __lg_flag is used by f77_abort to decide whether or not to dump memory */
operator|.
name|globl
name|__lg_flag
name|__lg_flag
operator|:
operator|.
name|long
literal|1
operator|.
name|text
end_expr_stmt

end_unit

