begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1994 by HOSOKAWA, Tatsumi<hosokawa@jp.FreeBSD.org>  *  * This software may be used, modified, copied, distributed, and sold,  * in both source and binary form provided that the above copyright and  * these terms are retained. Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with its  * use.  *  * Sep., 1994	Implemented on FreeBSD 1.1.5.1R (Toshiba AVS001WD)  *  *	$Id: apm_setup.h,v 1.4 1995/05/30 07:58:08 rgrimes Exp $  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|apm_version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|apm_cs_entry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|apm_cs32_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|apm_cs16_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|apm_ds_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|apm_cs_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|apm_ds_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|apm_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|kernelbase
decl_stmt|;
end_decl_stmt

end_unit

