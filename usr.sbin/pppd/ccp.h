begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ccp.h - Definitions for PPP Compression Control Protocol.  *  * Copyright (c) 1994 The Australian National University.  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation is hereby granted, provided that the above copyright  * notice appears in all copies.  This software is provided without any  * warranty, express or implied. The Australian National University  * makes no representations about the suitability of this software for  * any purpose.  *  * IN NO EVENT SHALL THE AUSTRALIAN NATIONAL UNIVERSITY BE LIABLE TO ANY  * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF  * THE AUSTRALIAN NATIONAL UNIVERSITY HAVE BEEN ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * THE AUSTRALIAN NATIONAL UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE AUSTRALIAN NATIONAL UNIVERSITY HAS NO  * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS,  * OR MODIFICATIONS.  *  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ccp_options
block|{
name|u_int
name|bsd_compress
range|:
literal|1
decl_stmt|;
comment|/* do BSD Compress? */
name|u_int
name|deflate
range|:
literal|1
decl_stmt|;
comment|/* do Deflate? (RFC code) */
name|u_int
name|baddeflate
range|:
literal|1
decl_stmt|;
comment|/* do Deflate? (Magnalink!) */
name|u_int
name|predictor_1
range|:
literal|1
decl_stmt|;
comment|/* do Predictor-1? */
name|u_int
name|predictor_2
range|:
literal|1
decl_stmt|;
comment|/* do Predictor-2? */
name|u_int
name|deflate_correct
range|:
literal|1
decl_stmt|;
comment|/* use correct code for deflate? */
name|u_int
name|deflate_draft
range|:
literal|1
decl_stmt|;
comment|/* use draft RFC code for deflate? */
name|u_short
name|bsd_bits
decl_stmt|;
comment|/* # bits/code for BSD Compress */
name|u_short
name|deflate_size
decl_stmt|;
comment|/* lg(window size) for Deflate */
name|u_short
name|baddeflate_size
decl_stmt|;
comment|/* lg(window size) for Deflate */
name|short
name|method
decl_stmt|;
comment|/* code for chosen compression method */
block|}
name|ccp_options
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|fsm
name|ccp_fsm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ccp_options
name|ccp_wantoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ccp_options
name|ccp_gotoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ccp_options
name|ccp_allowoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ccp_options
name|ccp_hisoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protent
name|ccp_protent
decl_stmt|;
end_decl_stmt

end_unit

