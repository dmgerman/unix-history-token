begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Exported interface to downloadable microcode for AdvanSys SCSI Adapters  *  * $FreeBSD$  *  * Obtained from:  *  * Copyright (c) 1995-1999 Advanced System Products, Inc.  * All Rights Reserved.  *     * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that redistributions of source  * code retain the above copyright notice and this comment without  * modification.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int16_t
name|adv_mcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int16_t
name|adv_mcode_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|adv_mcode_chksum
decl_stmt|;
end_decl_stmt

end_unit

