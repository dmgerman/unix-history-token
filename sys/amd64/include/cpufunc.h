begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Functions to provide access to special i386 instructions.  * XXX - bezillions more are defined in locore.s but are not declared anywhere.  *  *	$Id: cpufunc.h,v 1.9 1994/01/31 23:48:23 davidg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUFUNC_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"machine/spl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
specifier|static
specifier|inline
name|int
name|bdb
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|bdb_exists
decl_stmt|;
if|if
condition|(
operator|!
name|bdb_exists
condition|)
return|return
operator|(
literal|0
operator|)
return|;
asm|__asm("int $3");
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|disable_intr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("cli");
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|enable_intr
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("sti");
block|}
end_function

begin_comment
comment|/*  * This roundabout method of returning a u_char helps stop gcc-1.40 from  * generating unnecessary movzbl's.  */
end_comment

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|((u_char) u_int_inb(port))
end_define

begin_function
specifier|static
specifier|inline
name|u_int
name|u_int_inb
parameter_list|(
name|u_int
name|port
parameter_list|)
block|{
name|u_char
name|data
decl_stmt|;
comment|/* 	 * We use %%dx and not %1 here because i/o is done at %dx and not at 	 * %edx, while gcc-2.2.2 generates inferior code (movw instead of movl) 	 * if we tell it to load (u_short) port. 	 */
asm|__asm __volatile("inb %%dx,%0" : "=a" (data) : "d" (port));
return|return
name|data
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|outb
parameter_list|(
name|u_int
name|port
parameter_list|,
name|u_char
name|data
parameter_list|)
block|{
specifier|register
name|u_char
name|al
name|asm
argument_list|(
literal|"ax"
argument_list|)
decl_stmt|;
name|al
operator|=
name|data
expr_stmt|;
comment|/* help gcc-1.40's register allocator */
asm|__asm __volatile("outb %0,%%dx" : : "a" (al), "d" (port));
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|tlbflush
parameter_list|()
block|{
asm|__asm __volatile("movl %%cr3, %%eax; movl %%eax, %%cr3" : : : "ax");
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __GNUC__ */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|insque
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remque
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bdb
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disable_intr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|enable_intr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|inb
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|outb
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|,
name|u_int
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX - incompat */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_decl_stmt
name|void
name|load_cr0
name|__P
argument_list|(
operator|(
name|u_int
name|cr0
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|rcr0
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|load_cr3
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|rcr3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|rcr2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|setidt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|u_long
name|kvtop
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|outw
parameter_list|(
name|int
comment|/*u_short*/
parameter_list|,
name|int
comment|/*u_short*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX inline!*/
end_comment

begin_function_decl
specifier|extern
name|void
name|outsb
parameter_list|(
name|int
comment|/*u_short*/
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|outsw
parameter_list|(
name|int
comment|/*u_short*/
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insw
parameter_list|(
name|int
comment|/*u_short*/
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fillw
parameter_list|(
name|int
comment|/*u_short*/
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|filli
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CPUFUNC_H_ */
end_comment

end_unit

