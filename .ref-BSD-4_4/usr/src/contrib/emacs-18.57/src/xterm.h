begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_define
define|#
directive|define
name|XREPBUFSIZE
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rindex
decl_stmt|;
name|int
name|windex
decl_stmt|;
name|int
name|mindex
decl_stmt|;
name|XEvent
name|xrep
index|[
name|XREPBUFSIZE
index|]
decl_stmt|;
block|}
name|XREPBUFFER
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|x_edges_specified
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|sigmask
end_ifndef

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|no
parameter_list|)
value|(1L<< ((no) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGIO
end_ifdef

begin_define
define|#
directive|define
name|BLOCK_INPUT_DECLARE
parameter_list|()
value|int BLOCK_INPUT_mask;
end_define

begin_define
define|#
directive|define
name|BLOCK_INPUT
parameter_list|()
value|BLOCK_INPUT_mask = sigblock (sigmask (SIGIO))
end_define

begin_define
define|#
directive|define
name|UNBLOCK_INPUT
parameter_list|()
value|sigsetmask (BLOCK_INPUT_mask)
end_define

begin_define
define|#
directive|define
name|SIGNAL_INPUT
parameter_list|()
value|kill (XXpid, SIGIO)
end_define

begin_define
define|#
directive|define
name|RESIGNAL_INPUT
parameter_list|()
define|\
value|do									\ {									\   if (QLength ()> 0)							\     SIGNAL_INPUT ();							\ } while (0)
end_define

begin_define
define|#
directive|define
name|SIGNAL_INPUT_WHILE
parameter_list|(
name|flag
parameter_list|)
define|\
value|do									\ {									\   while (flag)								\     SIGNAL_INPUT ();							\ } while (0)
end_define

begin_define
define|#
directive|define
name|UNBLOCK_INPUT_RESIGNAL
parameter_list|()
define|\
value|do									\ {									\   UNBLOCK_INPUT ();							\   RESIGNAL_INPUT ();							\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SIGIO undefined */
end_comment

begin_define
define|#
directive|define
name|BLOCK_INPUT_DECLARE
parameter_list|()
end_define

begin_define
define|#
directive|define
name|BLOCK_INPUT
parameter_list|()
end_define

begin_define
define|#
directive|define
name|UNBLOCK_INPUT
parameter_list|()
end_define

begin_define
define|#
directive|define
name|SIGNAL_INPUT
parameter_list|()
end_define

begin_comment
comment|/* input_available_signal (0) */
end_comment

begin_define
define|#
directive|define
name|RESIGNAL_INPUT
parameter_list|()
end_define

begin_define
define|#
directive|define
name|SIGNAL_INPUT_WHILE
parameter_list|(
name|bitblt
parameter_list|)
end_define

begin_comment
comment|/* input_available_signal (0) */
end_comment

begin_define
define|#
directive|define
name|UNBLOCK_INPUT_RESIGNAL
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGIO */
end_comment

end_unit

