begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define how to access the int that the wait system call stores.    This has been compatible in all Unix systems since time immemorial,    but various well-meaning people have defined various different    words for the same old bits in the same old int (sometimes claimed    to be a struct).  We just know it's an int and we use these macros    to access the bits.  */
end_comment

begin_comment
comment|/* The following macros are defined equivalently to their definitions    in POSIX.1.  We fail to define WNOHANG and WUNTRACED, which POSIX.1<sys/wait.h> defines, since our code does not use waitpid().  We    also fail to declare wait() and waitpid().  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSIGNALED
end_ifndef

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) != 0177&& ((w)&~0377) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFSTOPPED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IBM6000
end_ifdef

begin_comment
comment|/* Unfortunately, the above comment (about being compatible in all Unix     systems) is not quite correct for AIX, sigh.  And AIX 3.2 can generate    status words like 0x57c (sigtrap received after load), and gdb would    choke on it. */
end_comment

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|w
parameter_list|)
value|((w)&0x40)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|w
parameter_list|)
value|(((w)&0377) == 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|w
parameter_list|)
value|(((w)>> 8)& 0377)
end_define

begin_comment
comment|/* same as WRETCODE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WTERMSIG
end_ifndef

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|w
parameter_list|)
value|((w)& 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSTOPSIG
end_ifndef

begin_define
define|#
directive|define
name|WSTOPSIG
value|WEXITSTATUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are not defined in POSIX, but are used by our programs.  */
end_comment

begin_define
define|#
directive|define
name|WAITTYPE
value|int
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|w
parameter_list|)
value|(((w)&0200) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSETEXIT
end_ifndef

begin_define
define|#
directive|define
name|WSETEXIT
parameter_list|(
name|w
parameter_list|,
name|status
parameter_list|)
value|((w) = (0 | ((status)<< 8)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WSETSTOP
end_ifndef

begin_define
define|#
directive|define
name|WSETSTOP
parameter_list|(
name|w
parameter_list|,
name|sig
parameter_list|)
value|((w) = (0177 | ((sig)<< 8)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

