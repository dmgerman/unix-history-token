begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_REG_
end_ifndef

begin_define
define|#
directive|define
name|_REG_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|I80960
end_ifdef

begin_comment
comment|/* Intel 960 register values passed over the wire by RPC:  */
end_comment

begin_struct
struct|struct
name|regs
block|{
name|int
name|r_lreg
index|[
literal|16
index|]
decl_stmt|;
comment|/* local registers              */
name|int
name|r_greg
index|[
literal|16
index|]
decl_stmt|;
comment|/* global registers             */
name|int
name|r_pcw
decl_stmt|;
comment|/* process control word         */
name|int
name|r_acw
decl_stmt|;
comment|/* arithmetic control word      */
name|int
name|r_tcw
decl_stmt|;
comment|/* trace control word           */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FP_REG_SIZE
value|12
end_define

begin_struct
struct|struct
name|fp_status
block|{
name|char
name|fps_regs
index|[
literal|4
index|]
index|[
name|FP_REG_SIZE
index|]
decl_stmt|;
comment|/* floating point regs */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* For now, just 68000 */
end_comment

begin_comment
comment|/* THE 68000 VERSION OF THIS FILE WAS `BORROWED' FROM A COPYRIGHTED    SUN MICROSYSTEMS INCLUDE FILE.  IT NEEDS TO BE REBUILT FROM SCRATCH.  	John Gilmore 	Cygnus Support  */
end_comment

begin_macro
name|FIXME
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !I80960 */
end_comment

begin_endif
endif|#
directive|endif
endif|!_REG_
end_endif

end_unit

