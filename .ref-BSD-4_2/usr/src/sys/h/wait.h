begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	wait.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * This file holds definitions relevent to the wait system call.  * Some of the options here are available only through the ``wait3''  * entry point; the old entry point with one argument has more fixed  * semantics, never returning status of unstopped children, hanging until  * a process terminates if any are outstanding, and never returns  * detailed information about process resource utilization (<vtimes.h>).  */
end_comment

begin_comment
comment|/*  * Structure of the information in the first word returned by both  * wait and wait3.  If w_stopval==WSTOPPED, then the second structure  * describes the information returned, else the first.  See WUNTRACED below.  */
end_comment

begin_union
union|union
name|wait
block|{
name|int
name|w_status
decl_stmt|;
comment|/* used in syscall */
comment|/* 	 * Terminated process status. 	 */
struct|struct
block|{
name|unsigned
name|short
name|w_Termsig
range|:
literal|7
decl_stmt|;
comment|/* termination signal */
name|unsigned
name|short
name|w_Coredump
range|:
literal|1
decl_stmt|;
comment|/* core dump indicator */
name|unsigned
name|short
name|w_Retcode
range|:
literal|8
decl_stmt|;
comment|/* exit code if w_termsig==0 */
block|}
name|w_T
struct|;
comment|/* 	 * Stopped process status.  Returned 	 * only for traced children unless requested 	 * with the WUNTRACED option bit. 	 */
struct|struct
block|{
name|unsigned
name|short
name|w_Stopval
range|:
literal|8
decl_stmt|;
comment|/* == W_STOPPED if stopped */
name|unsigned
name|short
name|w_Stopsig
range|:
literal|8
decl_stmt|;
comment|/* signal that stopped us */
block|}
name|w_S
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|w_termsig
value|w_T.w_Termsig
end_define

begin_define
define|#
directive|define
name|w_coredump
value|w_T.w_Coredump
end_define

begin_define
define|#
directive|define
name|w_retcode
value|w_T.w_Retcode
end_define

begin_define
define|#
directive|define
name|w_stopval
value|w_S.w_Stopval
end_define

begin_define
define|#
directive|define
name|w_stopsig
value|w_S.w_Stopsig
end_define

begin_define
define|#
directive|define
name|WSTOPPED
value|0177
end_define

begin_comment
comment|/* value of s.stopval if process is stopped */
end_comment

begin_comment
comment|/*  * Option bits for the second argument of wait3.  WNOHANG causes the  * wait to not hang if there are no stopped or terminated processes, rather  * returning an error indication in this case (pid==0).  WUNTRACED  * indicates that the caller should receive status about untraced children  * which stop due to signals.  If children are stopped and a wait without  * this option is done, it is as though they were still running... nothing  * about them is returned.  */
end_comment

begin_define
define|#
directive|define
name|WNOHANG
value|1
end_define

begin_comment
comment|/* dont hang in wait */
end_comment

begin_define
define|#
directive|define
name|WUNTRACED
value|2
end_define

begin_comment
comment|/* tell about stopped, untraced children */
end_comment

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|x
parameter_list|)
value|((x).w_stopval == WSTOPPED)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|x
parameter_list|)
value|((x).w_stopval != WSTOPPED&& (x).w_termsig != 0)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|x
parameter_list|)
value|((x).w_stopval != WSTOPPED&& (x).w_termsig == 0)
end_define

end_unit

