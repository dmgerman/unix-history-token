begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * %sccs.include.redist.c%  *  *	@(#)x25err.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   *    *  X.25 Reset and Clear errors and diagnostics.  These values are   *  returned in the u_error field of the u structure.  *  */
end_comment

begin_define
define|#
directive|define
name|EXRESET
value|100
end_define

begin_comment
comment|/* Reset: call reset			*/
end_comment

begin_define
define|#
directive|define
name|EXROUT
value|101
end_define

begin_comment
comment|/* Reset: out of order			*/
end_comment

begin_define
define|#
directive|define
name|EXRRPE
value|102
end_define

begin_comment
comment|/* Reset: remote procedure error	*/
end_comment

begin_define
define|#
directive|define
name|EXRLPE
value|103
end_define

begin_comment
comment|/* Reset: local procedure error		*/
end_comment

begin_define
define|#
directive|define
name|EXRNCG
value|104
end_define

begin_comment
comment|/* Reset: network congestion		*/
end_comment

begin_define
define|#
directive|define
name|EXCLEAR
value|110
end_define

begin_comment
comment|/* Clear: call cleared			*/
end_comment

begin_define
define|#
directive|define
name|EXCBUSY
value|111
end_define

begin_comment
comment|/* Clear: number busy			*/
end_comment

begin_define
define|#
directive|define
name|EXCOUT
value|112
end_define

begin_comment
comment|/* Clear: out of order			*/
end_comment

begin_define
define|#
directive|define
name|EXCRPE
value|113
end_define

begin_comment
comment|/* Clear: remote procedure error	*/
end_comment

begin_define
define|#
directive|define
name|EXCRRC
value|114
end_define

begin_comment
comment|/* Clear: collect call refused		*/
end_comment

begin_define
define|#
directive|define
name|EXCINV
value|115
end_define

begin_comment
comment|/* Clear: invalid call			*/
end_comment

begin_define
define|#
directive|define
name|EXCAB
value|116
end_define

begin_comment
comment|/* Clear: access barred			*/
end_comment

begin_define
define|#
directive|define
name|EXCLPE
value|117
end_define

begin_comment
comment|/* Clear: local procedure error		*/
end_comment

begin_define
define|#
directive|define
name|EXCNCG
value|118
end_define

begin_comment
comment|/* Clear: network congestion		*/
end_comment

begin_define
define|#
directive|define
name|EXCNOB
value|119
end_define

begin_comment
comment|/* Clear: not obtainable		*/
end_comment

end_unit

