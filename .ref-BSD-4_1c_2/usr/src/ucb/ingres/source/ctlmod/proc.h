begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  PROC.H -- process descriptors ** **	Version: **		@(#)proc.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CM_MAXPROC
end_ifndef

begin_define
define|#
directive|define
name|CM_MAXPROC
value|10
end_define

begin_comment
comment|/* maximum # of procs */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|pr_stat
decl_stmt|;
comment|/* status byte for this proc, see below */
name|char
name|pr_file
decl_stmt|;
comment|/* file descriptor to get to this proc */
name|char
name|pr_ninput
decl_stmt|;
comment|/* new cm_input after writing to this proc */
block|}
name|proc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PR_BCAST
value|00001
end_define

begin_comment
comment|/* write broadcasts on this pipe */
end_comment

begin_define
define|#
directive|define
name|PR_RADJCT
value|00002
end_define

begin_comment
comment|/* adjacent on read pipe */
end_comment

begin_define
define|#
directive|define
name|PR_WADJCT
value|00004
end_define

begin_comment
comment|/* adjacent on write pipe */
end_comment

begin_endif
endif|#
directive|endif
endif|CM_MAXPROC
end_endif

end_unit

