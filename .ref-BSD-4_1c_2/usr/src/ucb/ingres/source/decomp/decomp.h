begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **	This header file contains all the defined constant **	and special structures used by decomposition. Certain **	global variables which are referenced by many modules **	are also included. By convention global names always **	begin with a capital letter. ** **	Version: **		@(#)decomp.h	7.2	3/5/81 */
end_comment

begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_define
define|#
directive|define
name|OVHDP
value|2
end_define

begin_comment
comment|/*  overhead for a projection  */
end_comment

begin_define
define|#
directive|define
name|OVHDM
value|10
end_define

begin_comment
comment|/*  overhead for a modify  */
end_comment

begin_define
define|#
directive|define
name|MAXRELN
value|6
end_define

begin_comment
comment|/* size of relation descriptor cache */
end_comment

begin_define
define|#
directive|define
name|QBUFSIZ
value|2000
end_define

begin_comment
comment|/* buffer size (bytes) of original query tree */
end_comment

begin_define
define|#
directive|define
name|SQSIZ
value|10000
end_define

begin_comment
comment|/* buffer size for tree copies + sub-queries */
end_comment

begin_define
define|#
directive|define
name|AGBUFSIZ
value|350
end_define

begin_comment
comment|/* buffer size for temp agg tree components */
end_comment

begin_define
define|#
directive|define
name|PBUFSIZE
value|500
end_define

begin_comment
comment|/* size of parameter buffer area for setp() */
end_comment

begin_define
define|#
directive|define
name|PARGSIZE
value|PV_MAXPC
end_define

begin_comment
comment|/* max number of arguments for setp() */
end_comment

begin_comment
comment|/* error messages */
end_comment

begin_define
define|#
directive|define
name|NODESCAG
value|4602
end_define

begin_comment
comment|/* no descriptor for aggr func */
end_comment

begin_define
define|#
directive|define
name|QBUFFULL
value|4610
end_define

begin_comment
comment|/* Initial query buffer overflow */
end_comment

begin_define
define|#
directive|define
name|SQBUFFULL
value|4612
end_define

begin_comment
comment|/* sub-query buffer overflow */
end_comment

begin_define
define|#
directive|define
name|STACKFULL
value|4613
end_define

begin_comment
comment|/* trbuild stack overflow */
end_comment

begin_define
define|#
directive|define
name|AGBUFFULL
value|4614
end_define

begin_comment
comment|/* agg buffer overflow */
end_comment

begin_define
define|#
directive|define
name|AGFTOBIG
value|4615
end_define

begin_comment
comment|/* agg function exceeds MAXTUP or MAXDOM */
end_comment

begin_define
define|#
directive|define
name|TOOMANYAGGS
value|4616
end_define

begin_comment
comment|/* more than MAXAGG aggregates */
end_comment

begin_define
define|#
directive|define
name|RETUTOBIG
value|4620
end_define

begin_comment
comment|/* retr unique target list exceeds MAXTUP */
end_comment

begin_comment
comment|/* symbolic values for GETNXT parameter of fcn GET */
end_comment

begin_define
define|#
directive|define
name|NXTTUP
value|1
end_define

begin_comment
comment|/* get next tuple after one specified by tid */
end_comment

begin_comment
comment|/* flag for no result relation */
end_comment

begin_define
define|#
directive|define
name|NORESULT
value|-1
end_define

begin_comment
comment|/* Range table slot which is always free for aggregate temp rels */
end_comment

begin_define
define|#
directive|define
name|FREEVAR
value|MAXRANGE
end_define

begin_comment
comment|/* free var number for aggs */
end_comment

begin_comment
comment|/* Range table slot which is used for secondary index */
end_comment

begin_define
define|#
directive|define
name|SECINDVAR
value|MAXRANGE + 1
end_define

begin_define
define|#
directive|define
name|FIRSTNUM
value|MAXRANGE + 3
end_define

begin_define
define|#
directive|define
name|LASTNUM
value|100
end_define

end_unit

