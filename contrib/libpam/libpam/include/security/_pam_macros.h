begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PAM_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|PAM_MACROS_H
end_define

begin_comment
comment|/*  * All kind of macros used by PAM, but usable in some other  * programs too.  * Organized by Cristian Gafton<gafton@redhat.com>  * $FreeBSD$  */
end_comment

begin_comment
comment|/* a 'safe' version of strdup */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|x_strdup
parameter_list|(
name|s
parameter_list|)
value|( (s) ? strdup(s):NULL )
end_define

begin_comment
comment|/* Good policy to strike out passwords with some characters not just    free the memory */
end_comment

begin_define
define|#
directive|define
name|_pam_overwrite
parameter_list|(
name|x
parameter_list|)
define|\
value|do {                             \      register char *__xx__;      \      if ((__xx__=(x)))           \           while (*__xx__)        \                *__xx__++ = '\0'; \ } while (0)
end_define

begin_comment
comment|/*  * Don't just free it, forget it too.  */
end_comment

begin_define
define|#
directive|define
name|_pam_drop
parameter_list|(
name|X
parameter_list|)
define|\
value|do {                 \     if (X) {         \         free(X);     \         X=NULL;      \     }                \ } while (0)
end_define

begin_define
define|#
directive|define
name|_pam_drop_reply
parameter_list|(
comment|/* struct pam_response * */
name|reply
parameter_list|,
comment|/* int */
name|replies
parameter_list|)
define|\
value|do {                                              \     int reply_i;                                  \                                                   \     for (reply_i=0; reply_i<replies; ++reply_i) { \ 	if (reply[reply_i].resp) {                \ 	    _pam_overwrite(reply[reply_i].resp);  \ 	    free(reply[reply_i].resp);            \ 	}                                         \     }                                             \     if (reply)                                    \ 	free(reply);                              \ } while (0)
end_define

begin_comment
comment|/* some debugging code */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  * This provides the necessary function to do debugging in PAM.  * Cristian Gafton<gafton@redhat.com>  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * This is for debugging purposes ONLY. DO NOT use on live systems !!!  * You have been warned :-) - CG  *  * to get automated debugging to the log file, it must be created manually.  * _PAM_LOGFILE must exist, mode 666  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PAM_LOGFILE
end_ifndef

begin_define
define|#
directive|define
name|_PAM_LOGFILE
value|"/tmp/pam-debug.log"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|_pam_output_debug_info
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|fn
parameter_list|,
specifier|const
name|int
name|line
parameter_list|)
block|{
name|FILE
modifier|*
name|logfile
decl_stmt|;
name|int
name|must_close
init|=
literal|1
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|logfile
operator|=
name|fopen
argument_list|(
name|_PAM_LOGFILE
argument_list|,
literal|"a"
argument_list|)
operator|)
condition|)
block|{
name|logfile
operator|=
name|stderr
expr_stmt|;
name|must_close
operator|=
literal|0
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|logfile
argument_list|,
literal|"[%s:%s(%d)] "
argument_list|,
name|file
argument_list|,
name|fn
argument_list|,
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
name|must_close
condition|)
block|{
name|fflush
argument_list|(
name|logfile
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|logfile
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|_pam_output_debug
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|FILE
modifier|*
name|logfile
decl_stmt|;
name|int
name|must_close
init|=
literal|1
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|logfile
operator|=
name|fopen
argument_list|(
name|_PAM_LOGFILE
argument_list|,
literal|"a"
argument_list|)
operator|)
condition|)
block|{
name|logfile
operator|=
name|stderr
expr_stmt|;
name|must_close
operator|=
literal|0
expr_stmt|;
block|}
name|vfprintf
argument_list|(
name|logfile
argument_list|,
name|format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|logfile
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|must_close
condition|)
block|{
name|fflush
argument_list|(
name|logfile
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|logfile
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|do { \     _pam_output_debug_info(__FILE__, __FUNCTION__, __LINE__); \     _pam_output_debug x ; \ } while (0)
end_define

begin_define
define|#
directive|define
name|_pam_show_mem
parameter_list|(
name|X
parameter_list|,
name|XS
parameter_list|)
value|do {                                      \       int i;                                                          \       register unsigned char *x;                                      \       x = (unsigned char *)X;                                         \       fprintf(stderr, "<start at %p>\n", X);                        \       for (i = 0; i< XS ; ++x, ++i) {                                \           fprintf(stderr, "    %02X.<%p:%02X>\n", i, x, *x);         \       }                                                               \       fprintf(stderr, "<end for %p after %d bytes>\n", X, XS);      \ } while (0)
end_define

begin_define
define|#
directive|define
name|_pam_show_reply
parameter_list|(
comment|/* struct pam_response * */
name|reply
parameter_list|,
comment|/* int */
name|replies
parameter_list|)
define|\
value|do {                                                                        \     int reply_i;                                                            \     setbuf(stderr, NULL);                                                   \     fprintf(stderr, "array at %p of size %d\n",reply,replies);              \     fflush(stderr);                                                         \     if (reply) {                                                            \ 	for (reply_i = 0; reply_i< replies; reply_i++) {                   \ 	    fprintf(stderr, "  elem# %d at %p: resp = %p, retcode = %d\n",  \ 		    reply_i, reply+reply_i, reply[reply_i].resp,            \ 		    reply[reply_i].resp, _retcode);                         \ 	    fflush(stderr);                                                 \ 	    if (reply[reply_i].resp) {                                      \ 		fprintf(stderr, "    resp[%d] = '%s'\n",                    \ 			strlen(reply[reply_i].resp), reply[reply_i].resp);  \ 		fflush(stderr);                                             \ 	    }                                                               \ 	}                                                                   \     }                                                                       \     fprintf(stderr, "done here\n");                                         \     fflush(stderr);                                                         \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|_pam_show_mem
parameter_list|(
name|X
parameter_list|,
name|XS
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|_pam_show_reply
parameter_list|(
name|reply
parameter_list|,
name|replies
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAM_MACROS_H */
end_comment

end_unit

