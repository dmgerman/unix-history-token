begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/* static 	char sccsid[] = "@(#)machdep.h 1.1 %G%"; */
end_comment

begin_define
define|#
directive|define
name|pushaddr
value|push4
end_define

begin_define
define|#
directive|define
name|popaddr
value|(char *)pop4
end_define

begin_define
define|#
directive|define
name|popargs
parameter_list|(
name|num
parameter_list|)
value|popsp(num * sizeof(int))
end_define

end_unit

