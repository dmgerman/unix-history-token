begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	protmod.h		Protected Mode Utilities  *  *	(C) 1994 by Christian Gusenbauer (cg@fimp01.fim.uni-linz.ac.at)  *	All Rights Reserved.  *   *	Permission to use, copy, modify and distribute this software and its  *	documentation is hereby granted, provided that both the copyright  *	notice and this permission notice appear in all copies of the  *	software, derivative works or modified versions, and any portions  *	thereof, and that both notices appear in supporting documentation.  *   *	I ALLOW YOU USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION. I DISCLAIM  *	ANY LIABILITY OF ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE  *	USE OF THIS SOFTWARE.  *   */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo
name|bootinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|VCPIboot
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|pm_copy
parameter_list|(
name|char
name|far
modifier|*
name|from
parameter_list|,
name|unsigned
name|long
name|to
parameter_list|,
name|unsigned
name|long
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pm_copy copies "count" bytes from location "from" (valid C pointer) to the  * address "to" in the high-memory space.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|startprog
parameter_list|(
name|long
name|hmaddress
parameter_list|,
name|long
name|size
parameter_list|,
name|long
name|startaddr
parameter_list|,
name|long
name|loadflags
parameter_list|,
name|long
name|bootdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* startprog switches to protected mode, moves the kernel from hmaddress  * to 0x100000l and finally starts the kernel.  */
end_comment

begin_function_decl
specifier|extern
name|long
name|get_high_memory
parameter_list|(
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get_high_memory allocates size bytes from high memory (>1MB) and returns  * the address of this area.  */
end_comment

end_unit

