begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xdr_regs.h - xdr header for 68k registers */
end_comment

begin_comment
comment|/*  Copyright 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01a,05jun90,llk  extracted from xdr_regs.h. */
end_comment

begin_comment
comment|/* xdr structures are defined in reg.h (a bad place for them, i might add) */
end_comment

begin_function_decl
name|bool_t
name|xdr_regs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_ext_fp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_fp_status
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_fpa_status
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_fpa_long
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_fpa_regs
parameter_list|()
function_decl|;
end_function_decl

end_unit

