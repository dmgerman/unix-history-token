begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:55:13 1983 by jkf]-  * 	frame.h				$Locker:  $  * non local goto frame definition  *  * $Header: frame.h,v 1.3 83/09/12 15:29:08 sklower Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/* classes of frames: */
end_comment

begin_define
define|#
directive|define
name|F_PROG
value|1
end_define

begin_define
define|#
directive|define
name|F_CATCH
value|2
end_define

begin_define
define|#
directive|define
name|F_RESET
value|3
end_define

begin_define
define|#
directive|define
name|F_EVAL
value|4
end_define

begin_define
define|#
directive|define
name|F_FUNCALL
value|5
end_define

begin_define
define|#
directive|define
name|F_TO_FORT
value|6
end_define

begin_define
define|#
directive|define
name|F_TO_LISP
value|7
end_define

begin_comment
comment|/* classes of things thrown up */
end_comment

begin_define
define|#
directive|define
name|C_INITIAL
value|0
end_define

begin_define
define|#
directive|define
name|C_GO
value|1
end_define

begin_define
define|#
directive|define
name|C_RET
value|2
end_define

begin_define
define|#
directive|define
name|C_THROW
value|3
end_define

begin_define
define|#
directive|define
name|C_RESET
value|4
end_define

begin_define
define|#
directive|define
name|C_FRETURN
value|5
end_define

begin_comment
comment|/* the evaluation frame sits on the C runtime stack.  the global variable errp    points to the newest frame. The base of the frame points in the middle    of the frame, but in such a way that above the frame base the contents    are the same for all implementation, and below it there are different    saved registers for each machine.  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|struct
name|argent
modifier|*
name|svlbot
decl_stmt|,
modifier|*
name|svnp
decl_stmt|;
name|struct
name|nament
modifier|*
name|svbnp
decl_stmt|;
name|struct
name|frame
modifier|*
name|olderrp
decl_stmt|;
name|lispval
name|retaddr
decl_stmt|;
name|long
name|class
decl_stmt|;
name|lispval
name|larg1
decl_stmt|;
comment|/* optional */
name|lispval
name|larg2
decl_stmt|;
comment|/* optional */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|frame
modifier|*
name|errp
decl_stmt|,
modifier|*
name|Pushframe
argument_list|()
decl_stmt|,
modifier|*
name|Ipushf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stuff for IBM, RIDGE, DEC-VMS CC, maybe Bellmac-32  *  * The non obvious requirement is that any new function  * requiring a Pushframe must declare   *  * 	pbuf pb;  *  * as well.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPISFP
end_ifdef

begin_define
define|#
directive|define
name|Pushframe
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|Ipushf(a,b,c,&pb)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|pframe
block|{
name|long
name|regs
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|frame
name|f
decl_stmt|;
block|}
name|pbuf
typedef|;
end_typedef

end_unit

