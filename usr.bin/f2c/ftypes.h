begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* variable types (stored in the   vtype  field of   expptr)  * numeric assumptions:  *	int< reals< complexes  *	TYDREAL-TYREAL = TYDCOMPLEX-TYCOMPLEX  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_TYQUAD
end_ifdef

begin_undef
undef|#
directive|undef
name|TYQUAD
end_undef

begin_define
define|#
directive|define
name|TYQUAD_inc
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TYQUAD
value|5
end_define

begin_define
define|#
directive|define
name|TYQUAD_inc
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TYUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TYADDR
value|1
end_define

begin_define
define|#
directive|define
name|TYINT1
value|2
end_define

begin_define
define|#
directive|define
name|TYSHORT
value|3
end_define

begin_define
define|#
directive|define
name|TYLONG
value|4
end_define

begin_comment
comment|/* #define TYQUAD 5 */
end_comment

begin_define
define|#
directive|define
name|TYREAL
value|(5+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYDREAL
value|(6+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYCOMPLEX
value|(7+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYDCOMPLEX
value|(8+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYLOGICAL1
value|(9+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYLOGICAL2
value|(10+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYLOGICAL
value|(11+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYCHAR
value|(12+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYSUBR
value|(13+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYERROR
value|(14+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYCILIST
value|(15+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYICILIST
value|(16+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYOLIST
value|(17+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYCLLIST
value|(18+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYALIST
value|(19+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYINLIST
value|(20+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYVOID
value|(21+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYLABEL
value|(22+TYQUAD_inc)
end_define

begin_define
define|#
directive|define
name|TYFTNLEN
value|(23+TYQUAD_inc)
end_define

begin_comment
comment|/* TYVOID is not in any tables. */
end_comment

begin_comment
comment|/* NTYPES, NTYPES0 -- Total number of types, used to allocate tables indexed by    type.  Such tables can include the size (in bytes) of objects of a given    type, or labels for returning objects of different types from procedures    (see array   rtvlabels)   */
end_comment

begin_define
define|#
directive|define
name|NTYPES
value|TYVOID
end_define

begin_define
define|#
directive|define
name|NTYPES0
value|TYCILIST
end_define

begin_define
define|#
directive|define
name|TYBLANK
value|TYSUBR
end_define

begin_comment
comment|/* Huh? */
end_comment

end_unit

