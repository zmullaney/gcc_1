/* Macros to initialize the lang_hooks data structure.
   Copyright 2001 Free Software Foundation, Inc.
   Contributed by Alexandre Oliva  <aoliva@redhat.com>

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#ifndef GCC_LANG_HOOKS_H
#define GCC_LANG_HOOKS_H

/* Older hooks, that don't go in sub-structures for backward
   compatibility.  */
#ifndef LANG_HOOKS_INIT
#define LANG_HOOKS_INIT NULL
#endif
#ifndef LANG_HOOKS_FINISH
#define LANG_HOOKS_FINISH NULL
#endif
#ifndef LANG_HOOKS_INIT_OPTIONS
#define LANG_HOOKS_INIT_OPTIONS NULL
#endif
#ifndef LANG_HOOKS_DECODE_OPTION
#define LANG_HOOKS_DECODE_OPTION NULL
#endif
#ifndef LANG_HOOKS_POST_OPTIONS
#define LANG_HOOKS_POST_OPTIONS NULL
#endif
#ifndef LANG_HOOKS_HONOR_READONLY
#define LANG_HOOKS_HONOR_READONLY 0
#endif

/* Declarations of default tree inlining hooks.  */
tree tree_inlining_default_hook_walk_subtrees PARAMS ((tree*, int *,
						       walk_tree_fn,
						       void *, void *));
int tree_inlining_default_hook_cannot_inline_tree_fn PARAMS ((tree*));
int tree_inlining_default_hook_disregard_inline_limits PARAMS ((tree));
tree tree_inlining_default_hook_add_pending_fn_decls PARAMS ((void*, tree));
int tree_inlining_default_hook_tree_chain_matters_p PARAMS ((tree));
int tree_inlining_default_hook_auto_var_in_fn_p PARAMS ((tree, tree));
tree tree_inlining_default_hook_copy_res_decl_for_inlining PARAMS ((tree, tree,
								    tree,
								    void *,
								    int *,
								    void *));
int tree_inlining_default_hook_anon_aggr_type_p PARAMS ((tree));

/* Tree inlining hooks.  */
#ifndef LANG_HOOKS_TREE_INLINING_WALK_SUBTREES
#define LANG_HOOKS_TREE_INLINING_WALK_SUBTREES \
  tree_inlining_default_hook_walk_subtrees
#endif
#ifndef LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN
#define LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN \
  tree_inlining_default_hook_cannot_inline_tree_fn
#endif
#ifndef LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS
#define LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS \
  tree_inlining_default_hook_disregard_inline_limits
#endif
#ifndef LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS
#define LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS \
  tree_inlining_default_hook_add_pending_fn_decls
#endif
#ifndef LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P
#define LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P \
  tree_inlining_default_hook_tree_chain_matters_p
#endif
#ifndef LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P
#define LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P \
  tree_inlining_default_hook_auto_var_in_fn_p
#endif
#ifndef LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING
#define LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING \
  tree_inlining_default_hook_copy_res_decl_for_inlining
#endif
#ifndef LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P
#define LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P \
  tree_inlining_default_hook_anon_aggr_type_p
#endif

#define LANG_HOOKS_TREE_INLINING_INITIALIZER { \
  LANG_HOOKS_TREE_INLINING_WALK_SUBTREES, \
  LANG_HOOKS_TREE_INLINING_CANNOT_INLINE_TREE_FN, \
  LANG_HOOKS_TREE_INLINING_DISREGARD_INLINE_LIMITS, \
  LANG_HOOKS_TREE_INLINING_ADD_PENDING_FN_DECLS, \
  LANG_HOOKS_TREE_INLINING_TREE_CHAIN_MATTERS_P, \
  LANG_HOOKS_TREE_INLINING_AUTO_VAR_IN_FN_P, \
  LANG_HOOKS_TREE_INLINING_COPY_RES_DECL_FOR_INLINING, \
  LANG_HOOKS_TREE_INLINING_ANON_AGGR_TYPE_P \
} \

/* The whole thing.  The structure is defined in toplev.h.  */
#define LANG_HOOKS_INITIALIZER { \
  LANG_HOOKS_INIT, \
  LANG_HOOKS_FINISH, \
  LANG_HOOKS_INIT_OPTIONS, \
  LANG_HOOKS_DECODE_OPTION, \
  LANG_HOOKS_POST_OPTIONS, \
  LANG_HOOKS_HONOR_READONLY, \
  LANG_HOOKS_TREE_INLINING_INITIALIZER \
}

#endif /* GCC_LANG_HOOKS_H */
