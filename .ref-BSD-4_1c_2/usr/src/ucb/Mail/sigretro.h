begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * Define extra stuff not found in signal.h  * Sccs id @(#)sigretro.h	1.2	3/22/82  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGRETRO
end_ifndef

begin_define
define|#
directive|define
name|SIGRETRO
end_define

begin_comment
comment|/* Can use this for cond code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_HOLD
end_ifndef

begin_define
define|#
directive|define
name|SIG_HOLD
value|(int (*)()) 3
end_define

begin_comment
comment|/* Phony action to hold sig */
end_comment

begin_define
define|#
directive|define
name|BADSIG
value|(int (*)()) -1
end_define

begin_comment
comment|/* Return value on error */
end_comment

begin_endif
endif|#
directive|endif
endif|SIG_HOLD
end_endif

begin_endif
endif|#
directive|endif
endif|SIGRETRO
end_endif

end_unit

