begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    hv.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_comment
comment|/* typedefs to eliminate some typing */
end_comment

begin_typedef
typedef|typedef
name|struct
name|he
name|HE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hek
name|HEK
typedef|;
end_typedef

begin_comment
comment|/* entry in hash value chain */
end_comment

begin_struct
struct|struct
name|he
block|{
name|HE
modifier|*
name|hent_next
decl_stmt|;
comment|/* next entry in chain */
name|HEK
modifier|*
name|hent_hek
decl_stmt|;
comment|/* hash key */
name|SV
modifier|*
name|hent_val
decl_stmt|;
comment|/* scalar value that was hashed */
block|}
struct|;
end_struct

begin_comment
comment|/* hash key -- defined separately for use as shared pointer */
end_comment

begin_struct
struct|struct
name|hek
block|{
name|U32
name|hek_hash
decl_stmt|;
comment|/* hash of key */
name|I32
name|hek_len
decl_stmt|;
comment|/* length of hash key */
name|char
name|hek_key
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable-length hash key */
block|}
struct|;
end_struct

begin_comment
comment|/* hash structure: */
end_comment

begin_comment
comment|/* This structure must match the beginning of struct xpvmg in sv.h. */
end_comment

begin_struct
struct|struct
name|xpvhv
block|{
name|char
modifier|*
name|xhv_array
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xhv_fill
decl_stmt|;
comment|/* how full xhv_array currently is */
name|STRLEN
name|xhv_max
decl_stmt|;
comment|/* subscript of last element of xhv_array */
name|IV
name|xhv_keys
decl_stmt|;
comment|/* how many elements in the array */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* magic for scalar array */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|I32
name|xhv_riter
decl_stmt|;
comment|/* current root of iterator */
name|HE
modifier|*
name|xhv_eiter
decl_stmt|;
comment|/* current entry of iterator */
name|PMOP
modifier|*
name|xhv_pmroot
decl_stmt|;
comment|/* list of pm's for this package */
name|char
modifier|*
name|xhv_name
decl_stmt|;
comment|/* name, if a symbol table */
block|}
struct|;
end_struct

begin_comment
comment|/* hash a key */
end_comment

begin_define
define|#
directive|define
name|PERL_HASH
parameter_list|(
name|hash
parameter_list|,
name|str
parameter_list|,
name|len
parameter_list|)
define|\
value|STMT_START	{ \ 	register const char *s_PeRlHaSh = str; \ 	register I32 i_PeRlHaSh = len; \ 	register U32 hash_PeRlHaSh = 0; \ 	while (i_PeRlHaSh--) \ 	    hash_PeRlHaSh = hash_PeRlHaSh * 33 + *s_PeRlHaSh++; \ 	(hash) = hash_PeRlHaSh + (hash_PeRlHaSh>>5); \     } STMT_END
end_define

begin_comment
comment|/* =for apidoc AmU||HEf_SVKEY This flag, used in the length slot of hash entries and magic structures, specifies the structure contains a C<SV*> pointer where a C<char*> pointer is to be expected. (For information only--not to be used).  =for apidoc AmU||Nullhv Null HV pointer.  =for apidoc Am|char*|HvNAME|HV* stash Returns the package name of a stash.  See C<SvSTASH>, C<CvSTASH>.  =for apidoc Am|void*|HeKEY|HE* he Returns the actual pointer stored in the key slot of the hash entry. The pointer may be either C<char*> or C<SV*>, depending on the value of C<HeKLEN()>.  Can be assigned to.  The C<HePV()> or C<HeSVKEY()> macros are usually preferable for finding the value of a key.  =for apidoc Am|STRLEN|HeKLEN|HE* he If this is negative, and amounts to C<HEf_SVKEY>, it indicates the entry holds an C<SV*> key.  Otherwise, holds the actual length of the key.  Can be assigned to. The C<HePV()> macro is usually preferable for finding key lengths.  =for apidoc Am|SV*|HeVAL|HE* he Returns the value slot (type C<SV*>) stored in the hash entry.  =for apidoc Am|U32|HeHASH|HE* he Returns the computed hash stored in the hash entry.  =for apidoc Am|char*|HePV|HE* he|STRLEN len Returns the key slot of the hash entry as a C<char*> value, doing any necessary dereferencing of possibly C<SV*> keys.  The length of the string is placed in C<len> (this is a macro, so do I<not> use C<&len>).  If you do not care about what the length of the key is, you may use the global variable C<PL_na>, though this is rather less efficient than using a local variable.  Remember though, that hash keys in perl are free to contain embedded nulls, so using C<strlen()> or similar is not a good way to find the length of hash keys. This is very similar to the C<SvPV()> macro described elsewhere in this document.  =for apidoc Am|SV*|HeSVKEY|HE* he Returns the key as an C<SV*>, or C<Nullsv> if the hash entry does not contain an C<SV*> key.  =for apidoc Am|SV*|HeSVKEY_force|HE* he Returns the key as an C<SV*>.  Will create and return a temporary mortal C<SV*> if the hash entry contains only a C<char*> key.  =for apidoc Am|SV*|HeSVKEY_set|HE* he|SV* sv Sets the key to a given C<SV*>, taking care to set the appropriate flags to indicate the presence of an C<SV*> key, and returns the same C<SV*>.  =cut */
end_comment

begin_comment
comment|/* these hash entry flags ride on hent_klen (for use only in magic/tied HVs) */
end_comment

begin_define
define|#
directive|define
name|HEf_SVKEY
value|-2
end_define

begin_comment
comment|/* hent_key is a SV* */
end_comment

begin_define
define|#
directive|define
name|Nullhv
value|Null(HV*)
end_define

begin_define
define|#
directive|define
name|HvARRAY
parameter_list|(
name|hv
parameter_list|)
value|((HE**)((XPVHV*)  SvANY(hv))->xhv_array)
end_define

begin_define
define|#
directive|define
name|HvFILL
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_fill
end_define

begin_define
define|#
directive|define
name|HvMAX
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_max
end_define

begin_define
define|#
directive|define
name|HvKEYS
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_keys
end_define

begin_define
define|#
directive|define
name|HvRITER
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_riter
end_define

begin_define
define|#
directive|define
name|HvEITER
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_eiter
end_define

begin_define
define|#
directive|define
name|HvPMROOT
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_pmroot
end_define

begin_define
define|#
directive|define
name|HvNAME
parameter_list|(
name|hv
parameter_list|)
value|((XPVHV*)  SvANY(hv))->xhv_name
end_define

begin_define
define|#
directive|define
name|HvSHAREKEYS
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv)& SVphv_SHAREKEYS)
end_define

begin_define
define|#
directive|define
name|HvSHAREKEYS_on
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv) |= SVphv_SHAREKEYS)
end_define

begin_define
define|#
directive|define
name|HvSHAREKEYS_off
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv)&= ~SVphv_SHAREKEYS)
end_define

begin_define
define|#
directive|define
name|HvLAZYDEL
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv)& SVphv_LAZYDEL)
end_define

begin_define
define|#
directive|define
name|HvLAZYDEL_on
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv) |= SVphv_LAZYDEL)
end_define

begin_define
define|#
directive|define
name|HvLAZYDEL_off
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv)&= ~SVphv_LAZYDEL)
end_define

begin_comment
comment|/* Maybe amagical: */
end_comment

begin_comment
comment|/* #define HV_AMAGICmb(hv)      (SvFLAGS(hv)& (SVpgv_badAM | SVpgv_AM)) */
end_comment

begin_define
define|#
directive|define
name|HV_AMAGIC
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv)&   SVpgv_AM)
end_define

begin_define
define|#
directive|define
name|HV_AMAGIC_on
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv) |=  SVpgv_AM)
end_define

begin_define
define|#
directive|define
name|HV_AMAGIC_off
parameter_list|(
name|hv
parameter_list|)
value|(SvFLAGS(hv)&= ~SVpgv_AM)
end_define

begin_comment
comment|/* #define HV_AMAGICbad(hv)     (SvFLAGS(hv)& SVpgv_badAM) #define HV_badAMAGIC_on(hv)  (SvFLAGS(hv) |= SVpgv_badAM) #define HV_badAMAGIC_off(hv) (SvFLAGS(hv)&= ~SVpgv_badAM) */
end_comment

begin_define
define|#
directive|define
name|Nullhe
value|Null(HE*)
end_define

begin_define
define|#
directive|define
name|HeNEXT
parameter_list|(
name|he
parameter_list|)
value|(he)->hent_next
end_define

begin_define
define|#
directive|define
name|HeKEY_hek
parameter_list|(
name|he
parameter_list|)
value|(he)->hent_hek
end_define

begin_define
define|#
directive|define
name|HeKEY
parameter_list|(
name|he
parameter_list|)
value|HEK_KEY(HeKEY_hek(he))
end_define

begin_define
define|#
directive|define
name|HeKEY_sv
parameter_list|(
name|he
parameter_list|)
value|(*(SV**)HeKEY(he))
end_define

begin_define
define|#
directive|define
name|HeKLEN
parameter_list|(
name|he
parameter_list|)
value|HEK_LEN(HeKEY_hek(he))
end_define

begin_define
define|#
directive|define
name|HeVAL
parameter_list|(
name|he
parameter_list|)
value|(he)->hent_val
end_define

begin_define
define|#
directive|define
name|HeHASH
parameter_list|(
name|he
parameter_list|)
value|HEK_HASH(HeKEY_hek(he))
end_define

begin_define
define|#
directive|define
name|HePV
parameter_list|(
name|he
parameter_list|,
name|lp
parameter_list|)
value|((HeKLEN(he) == HEf_SVKEY) ?		\ 				 SvPV(HeKEY_sv(he),lp) :		\ 				 (((lp = HeKLEN(he))>= 0) ?		\ 				  HeKEY(he) : Nullch))
end_define

begin_define
define|#
directive|define
name|HeSVKEY
parameter_list|(
name|he
parameter_list|)
value|((HeKEY(he)&& 				\ 				  HeKLEN(he) == HEf_SVKEY) ?		\ 				 HeKEY_sv(he) : Nullsv)
end_define

begin_define
define|#
directive|define
name|HeSVKEY_force
parameter_list|(
name|he
parameter_list|)
value|(HeKEY(he) ?				\ 				 ((HeKLEN(he) == HEf_SVKEY) ?		\ 				  HeKEY_sv(he) :			\ 				  sv_2mortal(newSVpvn(HeKEY(he),	\ 						     HeKLEN(he)))) :	\&PL_sv_undef)
end_define

begin_define
define|#
directive|define
name|HeSVKEY_set
parameter_list|(
name|he
parameter_list|,
name|sv
parameter_list|)
value|((HeKLEN(he) = HEf_SVKEY), (HeKEY_sv(he) = sv))
end_define

begin_define
define|#
directive|define
name|Nullhek
value|Null(HEK*)
end_define

begin_define
define|#
directive|define
name|HEK_BASESIZE
value|STRUCT_OFFSET(HEK, hek_key[0])
end_define

begin_define
define|#
directive|define
name|HEK_HASH
parameter_list|(
name|hek
parameter_list|)
value|(hek)->hek_hash
end_define

begin_define
define|#
directive|define
name|HEK_LEN
parameter_list|(
name|hek
parameter_list|)
value|(hek)->hek_len
end_define

begin_define
define|#
directive|define
name|HEK_KEY
parameter_list|(
name|hek
parameter_list|)
value|(hek)->hek_key
end_define

begin_comment
comment|/* calculate HV array allocation */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STRANGE_MALLOC
argument_list|)
operator|||
name|defined
argument_list|(
name|MYMALLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_HV_ARRAY_ALLOC_BYTES
parameter_list|(
name|size
parameter_list|)
value|((size) * sizeof(HE*))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC_OVERHEAD
value|16
end_define

begin_define
define|#
directive|define
name|PERL_HV_ARRAY_ALLOC_BYTES
parameter_list|(
name|size
parameter_list|)
define|\
value|(((size)< 64)					\ 			 ? (size) * sizeof(HE*)				\ 			 : (size) * sizeof(HE*) * 2 - MALLOC_OVERHEAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

