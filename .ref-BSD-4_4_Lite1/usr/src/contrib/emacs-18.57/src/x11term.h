begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_include
include|#
directive|include
file|<X11/keysym.h>
end_include

begin_include
include|#
directive|include
file|<X11/cursorfont.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<X11/X10.h>
end_include

begin_define
define|#
directive|define
name|XMOUSEBUFSIZE
value|64
end_define

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

begin_define
define|#
directive|define
name|BLOCK_INPUT_DECLARE
parameter_list|()
value|int BLOCK_INPUT_mask
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SIGIO
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SIGIO */
end_comment

begin_define
define|#
directive|define
name|BLOCK_INPUT
parameter_list|()
value|stop_polling ()
end_define

begin_define
define|#
directive|define
name|UNBLOCK_INPUT
parameter_list|()
value|start_polling ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGIO */
end_comment

begin_define
define|#
directive|define
name|CLASS
value|"Emacs"
end_define

begin_comment
comment|/* class id for GNU Emacs, used in .Xdefaults, etc. */
end_comment

end_unit

