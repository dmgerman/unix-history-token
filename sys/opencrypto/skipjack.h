begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: skipjack.h,v 1.3 2002/03/14 01:26:51 millert Exp $	*/
end_comment

begin_comment
comment|/*-  * Further optimized test implementation of SKIPJACK algorithm   * Mark Tillotson<markt@chaos.org.uk>, 25 June 98  * Optimizations suit RISC (lots of registers) machine best.  *  * based on unoptimized implementation of  * Panu Rissanen<bande@lut.fi> 960624  *  * SKIPJACK and KEA Algorithm Specifications   * Version 2.0   * 29 May 1998 */
end_comment

begin_function_decl
specifier|extern
name|void
name|skipjack_forwards
parameter_list|(
name|u_int8_t
modifier|*
name|plain
parameter_list|,
name|u_int8_t
modifier|*
name|cipher
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|skipjack_backwards
parameter_list|(
name|u_int8_t
modifier|*
name|cipher
parameter_list|,
name|u_int8_t
modifier|*
name|plain
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|subkey_table_gen
parameter_list|(
name|u_int8_t
modifier|*
name|key
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
name|key_tables
parameter_list|)
function_decl|;
end_function_decl

end_unit

