begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CTL
parameter_list|(
name|c
parameter_list|)
value|((c)& 037)
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|((c) | 0200)
end_define

begin_define
define|#
directive|define
name|RUBOUT
value|'\177'
end_define

begin_define
define|#
directive|define
name|LF
value|CTL('J')
end_define

begin_define
define|#
directive|define
name|CR
value|CTL('M')
end_define

begin_define
define|#
directive|define
name|BS
value|CTL('H')
end_define

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

end_unit

