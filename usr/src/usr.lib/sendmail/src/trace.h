begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  Sendmail **  Copyright (c) 1983  Eric P. Allman **  Berkeley, California ** **  Copyright (c) 1983 Regents of the University of California. **  All rights reserved.  The Berkeley software License Agreement **  specifies the terms and conditions for redistribution. ** **	@(#)trace.h	5.1 (Berkeley) 7/14/85 */
end_comment

begin_comment
comment|/* **  Trace Package. */
end_comment

begin_typedef
typedef|typedef
name|u_char
modifier|*
name|TRACEV
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|TRACEV
name|tTvect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current trace vector */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tTVECT
end_ifndef

begin_define
define|#
directive|define
name|tTVECT
value|tTvect
end_define

begin_endif
endif|#
directive|endif
endif|tTVECT
end_endif

begin_define
define|#
directive|define
name|tTf
parameter_list|(
name|flag
parameter_list|,
name|level
parameter_list|)
value|(tTVECT[flag]>= level)
end_define

begin_define
define|#
directive|define
name|tTlevel
parameter_list|(
name|flag
parameter_list|)
value|(tTVECT[flag])
end_define

end_unit

