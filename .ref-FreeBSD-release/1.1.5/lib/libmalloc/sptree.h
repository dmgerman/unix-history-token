begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** sptree.h:  The following type declarations provide the binary tree **  representation of event-sets or priority queues needed by splay trees ** **  assumes that data and datb will be provided by the application **  to hold all application specific information ** **  assumes that key will be provided by the application, comparable **  with the compare function applied to the addresses of two keys. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPTREE_H
end_ifndef

begin_define
define|#
directive|define
name|SPTREE_H
end_define

begin_typedef
typedef|typedef
struct|struct
name|_spblk
block|{
name|struct
name|_spblk
modifier|*
name|leftlink
decl_stmt|;
name|struct
name|_spblk
modifier|*
name|rightlink
decl_stmt|;
name|struct
name|_spblk
modifier|*
name|uplink
decl_stmt|;
name|univptr_t
name|key
decl_stmt|;
comment|/* formerly time/timetyp */
name|univptr_t
name|data
decl_stmt|;
comment|/* formerly aux/auxtype */
name|univptr_t
name|datb
decl_stmt|;
block|}
name|SPBLK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|SPBLK
modifier|*
name|root
decl_stmt|;
comment|/* root node */
comment|/* Statistics, not strictly necessary, but handy for tuning  */
name|int
name|lookups
decl_stmt|;
comment|/* number of splookup()s */
name|int
name|lkpcmps
decl_stmt|;
comment|/* number of lookup comparisons */
name|int
name|enqs
decl_stmt|;
comment|/* number of spenq()s */
name|int
name|enqcmps
decl_stmt|;
comment|/* compares in spenq */
name|int
name|splays
decl_stmt|;
name|int
name|splayloops
decl_stmt|;
block|}
name|SPTREE
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__proto
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__proto
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sptree.c */
end_comment

begin_comment
comment|/* init tree */
end_comment

begin_decl_stmt
specifier|extern
name|SPTREE
modifier|*
name|__spinit
name|__proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* find key in a tree */
end_comment

begin_decl_stmt
specifier|extern
name|SPBLK
modifier|*
name|__splookup
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|SPTREE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enter an item, allocating or replacing */
end_comment

begin_decl_stmt
specifier|extern
name|SPBLK
modifier|*
name|__spadd
name|__proto
argument_list|(
operator|(
name|univptr_t
operator|,
name|univptr_t
operator|,
name|univptr_t
operator|,
name|SPTREE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scan forward through tree */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|__spscan
name|__proto
argument_list|(
operator|(
name|void
argument_list|(
argument|*
argument_list|)
name|__proto
argument_list|(
operator|(
name|SPBLK
operator|*
operator|)
argument_list|)
operator|,
name|SPBLK
operator|*
operator|,
name|SPTREE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return tree statistics */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__spstats
name|__proto
argument_list|(
operator|(
name|SPTREE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* delete node from tree */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|__spdelete
name|__proto
argument_list|(
operator|(
name|SPBLK
operator|*
operator|,
name|SPTREE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|__proto
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPTREE_H */
end_comment

end_unit

