begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: setjmp.h,v 1.2 2001/08/25 14:45:59 bjh21 Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * machine/setjmp.h: machine dependent setjmp-related information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SETJMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SETJMP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|_JBLEN
value|64
end_define

begin_comment
comment|/* size, in longs, of a jmp_buf */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_JBLEN
value|29
end_define

begin_comment
comment|/* size, in longs, of a jmp_buf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NOTE: The internal structure of a jmp_buf is *PRIVATE*  *       This information is provided as there is software  *       that fiddles with this with obtain the stack pointer  *	 (yes really ! and its commercial !).  *  * Description of the setjmp buffer  *  * word  0	magic number	(dependant on creator)  *       1 -  3	f4		fp register 4  *	 4 -  6	f5		fp register 5  *	 7 -  9 f6		fp register 6  *	10 - 12	f7		fp register 7  *	13	fpsr		fp status register  *	14	r4		register 4  *	15	r5		register 5  *	16	r6		register 6  *	17	r7		register 7  *	18	r8		register 8  *	19	r9		register 9  *	20	r10		register 10 (sl)  *	21	r11		register 11 (fp)  *	22	r12		register 12 (ip)  *	23	r13		register 13 (sp)  *	24	r14		register 14 (lr)  *	25	signal mask	(dependant on magic)  *	26	(con't)  *	27	(con't)  *	28	(con't)  *  * The magic number number identifies the jmp_buf and  * how the buffer was created as well as providing  * a sanity check  *  * A side note I should mention - Please do not tamper  * with the floating point fields. While they are  * always saved and restored at the moment this cannot  * be garenteed especially if the compiler happens  * to be generating soft-float code so no fp  * registers will be used.  *  * Whilst this can be seen an encouraging people to  * use the setjmp buffer in this way I think that it  * is for the best then if changes occur compiles will  * break rather than just having new builds falling over  * mysteriously.  */
end_comment

begin_define
define|#
directive|define
name|_JB_MAGIC__SETJMP
value|0x4278f500
end_define

begin_define
define|#
directive|define
name|_JB_MAGIC_SETJMP
value|0x4278f501
end_define

begin_comment
comment|/* Valid for all jmp_buf's */
end_comment

begin_define
define|#
directive|define
name|_JB_MAGIC
value|0
end_define

begin_define
define|#
directive|define
name|_JB_REG_F4
value|1
end_define

begin_define
define|#
directive|define
name|_JB_REG_F5
value|4
end_define

begin_define
define|#
directive|define
name|_JB_REG_F6
value|7
end_define

begin_define
define|#
directive|define
name|_JB_REG_F7
value|10
end_define

begin_define
define|#
directive|define
name|_JB_REG_FPSR
value|13
end_define

begin_define
define|#
directive|define
name|_JB_REG_R4
value|14
end_define

begin_define
define|#
directive|define
name|_JB_REG_R5
value|15
end_define

begin_define
define|#
directive|define
name|_JB_REG_R6
value|16
end_define

begin_define
define|#
directive|define
name|_JB_REG_R7
value|17
end_define

begin_define
define|#
directive|define
name|_JB_REG_R8
value|18
end_define

begin_define
define|#
directive|define
name|_JB_REG_R9
value|19
end_define

begin_define
define|#
directive|define
name|_JB_REG_R10
value|20
end_define

begin_define
define|#
directive|define
name|_JB_REG_R11
value|21
end_define

begin_define
define|#
directive|define
name|_JB_REG_R12
value|22
end_define

begin_define
define|#
directive|define
name|_JB_REG_R13
value|23
end_define

begin_define
define|#
directive|define
name|_JB_REG_R14
value|24
end_define

begin_comment
comment|/* Only valid with the _JB_MAGIC_SETJMP magic */
end_comment

begin_define
define|#
directive|define
name|_JB_SIGMASK
value|25
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_typedef
typedef|typedef
struct|struct
name|_sigjmp_buf
block|{
name|int
name|_sjb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|sigjmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_jmp_buf
block|{
name|int
name|_jb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|jmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SETJMP_H_ */
end_comment

end_unit

