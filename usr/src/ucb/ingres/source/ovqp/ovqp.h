begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*	@(#)ovqp.h	7.1	2/5/81	*/
end_comment

begin_comment
comment|/* **	This header file contains the external (global) declarations **	of variables and structures as well as the manifest constants **	particular to OVQP. ** **	By convention global variable identifiers are spelled with  **	an initial capital letter; manifest constants are in caps **	completely. */
end_comment

begin_comment
comment|/* **	Manifest constants */
end_comment

begin_define
define|#
directive|define
name|tTFLAG
value|'O'
end_define

begin_comment
comment|/* trace flag */
end_comment

begin_define
define|#
directive|define
name|LBUFSIZE
value|850
end_define

begin_comment
comment|/* buffer size for holding query list */
end_comment

begin_comment
comment|/* and concat and ascii buffers */
end_comment

begin_define
define|#
directive|define
name|NSIMP
value|15
end_define

begin_comment
comment|/*maximum no. of "simple clauses"  					 * allowed in Qual list 					 * (see "strategy" portion) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACKSIZ
end_ifndef

begin_define
define|#
directive|define
name|STACKSIZ
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXNODES
value|(2 * MAXDOM) + 50
end_define

begin_comment
comment|/* max nodes in De.ov_qvect */
end_comment

begin_comment
comment|/* symbolic values for GETNXT parameter of fcn GET */
end_comment

begin_define
define|#
directive|define
name|CURTUP
value|0
end_define

begin_comment
comment|/* get tuple specified by tid */
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
comment|/* symbolic values for CHECKDUPS param of fcn INSERT */
end_comment

begin_define
define|#
directive|define
name|DUPS
value|0
end_define

begin_comment
comment|/* allow a duplicate tuple to be inserted */
end_comment

begin_define
define|#
directive|define
name|NODUPS
value|1
end_define

begin_comment
comment|/* check for and avoid inserting  				 * a duplicate (if possible)*/
end_comment

begin_define
define|#
directive|define
name|TIDTYPE
value|INT
end_define

begin_define
define|#
directive|define
name|TIDLEN
value|4
end_define

begin_define
define|#
directive|define
name|CNTLEN
value|4
end_define

begin_comment
comment|/* counter for aggregate computations */
end_comment

begin_define
define|#
directive|define
name|CNTTYPE
value|INT
end_define

begin_comment
comment|/* counter type */
end_comment

begin_define
define|#
directive|define
name|OANYLEN
value|2
end_define

begin_comment
comment|/* length for opANY */
end_comment

begin_define
define|#
directive|define
name|OANYTYPE
value|INT
end_define

begin_comment
comment|/* type for opANY */
end_comment

begin_comment
comment|/* error codes for errors caused by user query ie. not syserrs */
end_comment

begin_define
define|#
directive|define
name|LISTFULL
value|4100
end_define

begin_comment
comment|/* postfix query list full */
end_comment

begin_define
define|#
directive|define
name|BADCONV
value|4101
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|BADUOPC
value|4102
end_define

begin_comment
comment|/* Unary operator not allowed on char fields */
end_comment

begin_define
define|#
directive|define
name|BADMIX
value|4103
end_define

begin_comment
comment|/* can't assign, compare or operate a numberic with a char */
end_comment

begin_define
define|#
directive|define
name|BADSUMC
value|4104
end_define

begin_comment
comment|/* can't sum char domains (aggregate) */
end_comment

begin_define
define|#
directive|define
name|BADAVG
value|4105
end_define

begin_comment
comment|/* can't avg char domains (aggregate) */
end_comment

begin_define
define|#
directive|define
name|STACKOVER
value|4106
end_define

begin_comment
comment|/* shorterpreter stack overflow */
end_comment

begin_define
define|#
directive|define
name|CBUFULL
value|4107
end_define

begin_comment
comment|/* not enough space for concat or ascii operation */
end_comment

begin_define
define|#
directive|define
name|BADCHAR
value|4108
end_define

begin_comment
comment|/* arithmetic operation on two character fields */
end_comment

begin_define
define|#
directive|define
name|NUMERIC
value|4109
end_define

begin_comment
comment|/* numeric field in a character operator */
end_comment

begin_define
define|#
directive|define
name|FLOATEXCEP
value|4110
end_define

begin_comment
comment|/* floating poshort exception */
end_comment

begin_define
define|#
directive|define
name|CHARCONVERT
value|4111
end_define

begin_comment
comment|/* bad ascii to numeric conversion */
end_comment

begin_define
define|#
directive|define
name|NODOVFLOW
value|4112
end_define

begin_comment
comment|/* node vector overflow */
end_comment

begin_define
define|#
directive|define
name|COMPNOSP
value|4113
end_define

begin_comment
comment|/* code table overflow */
end_comment

begin_define
define|#
directive|define
name|COMPNOREGS
value|4114
end_define

begin_comment
comment|/* no more registers */
end_comment

begin_define
define|#
directive|define
name|BADSECINDX
value|4199
end_define

begin_comment
comment|/* found a 6.0 sec index */
end_comment

begin_comment
comment|/* (i.e. either De.ov_srcdesc or Ov.ov_indesc) */
end_comment

begin_typedef
typedef|typedef
name|char
name|i1type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|i2type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|i4type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|f4type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|f8type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|c0type
index|[]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|stringp
typedef|;
end_typedef

end_unit

