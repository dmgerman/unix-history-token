begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)samachdep.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|NHPIB
value|4
end_define

begin_define
define|#
directive|define
name|NITE
value|4
end_define

begin_define
define|#
directive|define
name|NSCSI
value|2
end_define

begin_define
define|#
directive|define
name|NRD
value|(NHPIB * 8)
end_define

begin_define
define|#
directive|define
name|NCT
value|(NHPIB * 8)
end_define

begin_define
define|#
directive|define
name|NSD
value|(NSCSI * 8)
end_define

begin_define
define|#
directive|define
name|IOV
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_decl_stmt
specifier|extern
name|int
name|howto
decl_stmt|,
name|devtype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bogon grfinfo structure to keep grf_softc happy */
end_comment

begin_struct
struct|struct
name|grfinfo
block|{
name|int
name|grf_foo
decl_stmt|;
block|}
struct|;
end_struct

end_unit

