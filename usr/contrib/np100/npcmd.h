begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 MICOM-Interlan, Inc., Boxborough Mass.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)npcmd.h	6.1 (Berkeley) 2/20/86  *  @(#)NP Series Drivers npcmd.h	1.1  *  * Delta Created 9/19/85			Date Extracted 9/20/85  * File name ../../sccs/h/s.npcmd.h  */
end_comment

begin_comment
comment|/* Note that the NPUNIT macro must match that defined in "npreg.h" */
end_comment

begin_define
define|#
directive|define
name|NPUNIT
parameter_list|(
name|a
parameter_list|)
value|((minor(a)>> 4)& 0x0F)
end_define

begin_define
define|#
directive|define
name|NPRESET
value|0x01
end_define

begin_comment
comment|/* reset the board */
end_comment

begin_define
define|#
directive|define
name|NPSTART
value|0x04
end_define

begin_comment
comment|/* start board execution */
end_comment

begin_define
define|#
directive|define
name|NPGPANIC
value|0x05
end_define

begin_comment
comment|/* Get panic message */
end_comment

begin_define
define|#
directive|define
name|NPINIT
value|0x06
end_define

begin_comment
comment|/* initialize software on board */
end_comment

begin_define
define|#
directive|define
name|NPSTATS
value|0x07
end_define

begin_define
define|#
directive|define
name|NPRCSR0
value|0x08
end_define

begin_comment
comment|/* read CSR0 */
end_comment

begin_define
define|#
directive|define
name|NPRCSR1
value|0x09
end_define

begin_comment
comment|/* read CSR1 */
end_comment

begin_define
define|#
directive|define
name|NPRCSR2
value|0x0a
end_define

begin_comment
comment|/* read CSR2 */
end_comment

begin_define
define|#
directive|define
name|NPRCSR3
value|0x0b
end_define

begin_comment
comment|/* read CSR3 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR0
value|0x0c
end_define

begin_comment
comment|/* write CSR0 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR1
value|0x0d
end_define

begin_comment
comment|/* write CSR1 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR2
value|0x0e
end_define

begin_comment
comment|/* write CSR2 */
end_comment

begin_define
define|#
directive|define
name|NPWCSR3
value|0x0f
end_define

begin_comment
comment|/* write CSR3 */
end_comment

begin_define
define|#
directive|define
name|NPPOLL
value|0x10
end_define

begin_define
define|#
directive|define
name|NPKILL
value|0x11
end_define

begin_define
define|#
directive|define
name|NPSETPROT
value|0x12
end_define

begin_comment
comment|/* set the protocol to use */
end_comment

begin_define
define|#
directive|define
name|NPSETBOARD
value|0x13
end_define

begin_comment
comment|/* set board to use */
end_comment

begin_define
define|#
directive|define
name|NPSETNPDEB
value|0x14
end_define

begin_comment
comment|/* set nc debuging level */
end_comment

begin_define
define|#
directive|define
name|NPSETADDR
value|0x15
end_define

begin_comment
comment|/* set host address */
end_comment

begin_define
define|#
directive|define
name|NPNETBOOT
value|0x16
end_define

begin_comment
comment|/* boot from the network */
end_comment

begin_comment
comment|/* ICP Board Requests */
end_comment

begin_define
define|#
directive|define
name|ICPLOAD
value|0x02
end_define

begin_define
define|#
directive|define
name|ICPDUMP
value|0x03
end_define

begin_define
define|#
directive|define
name|ICPPANIC
value|0x05
end_define

begin_define
define|#
directive|define
name|ICPPOLL
value|0x10
end_define

end_unit

