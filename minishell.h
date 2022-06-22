/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/22 03:09:31 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H
// ********************************************** includes
# include "headers/includes.h"
# include "headers/macros.h"
# include "headers/structs.h"
# include "execution/headers/execution.h"
// *************************************** lexer 
//------------------ utils
t_data	*ft_lstnew_lexer(char *data, int token);
void	ft_lstadd_back_lexer(t_data **lst, t_data *new);
t_data	*ft_lstlast_lexer(t_data **lst);
//------------------ lexer functions
int		check_syntax_error(char *buffer);
int		ft_is_operator(char c);
int		ft_special_char(char c);
int		check_the_operator(char c);
t_data	*analyse_buffer(char *buffer);
int		operator_error(char *buffer, int i);
//-------------------- token and save data
int		data_reconization(char *buffer, t_data **data);
int		operator_type(char **buffer, t_data **data);
int		word_token(char **buffer, t_data **data, char *quote);
int		pipe_data(char **buffer, t_data **data);
int		save_operator_data(char **buffer, t_data **data, int flag);
void	check_flag(char **buffer, int flag);
int		count_cmd_word_len(char **buffer);
//------------------------------ utils
void	free_data(t_data **data);
//*************************************************** expander
//--------------------------- utils
t_env	*ft_lstnew_expander(char *var, char *value);
void	ft_lstadd_back_expander(t_env **lst, t_env *new);
t_env	*ft_lstlast_expander(t_env **lst);
void	free_data2(t_env **env);
//---------------------------- get env
t_env	*get_env(char **env);
char *get_var(char *line);
char *get_value(char *line);
char	*var_finder(char *var, t_env *env);
//-----------------------------------------
void	quotes_checker(char quote, char *quote_type);
char	*expande_str_data(char *str, t_env *env, int token);
void	expander(t_shell *data_shell); 
int		dollar_var(char **str, t_env *env);
char	*before(char *str);
char	*after(char *str);
char *in_var(char *str, t_env *env);
//****************************************************** data orinizer 
void	redirection_organizer(t_shell *global_data);
#endif
// lala matms7ch hadchi  rah kan7fdo  o ana kancoder
// يا أَيُّها المَلِكُ الَّذي راحاتُهُ
// قامَت مَقامَ الغَيثِ في أَزمانِهِ
// يا قِبلَةَ القُصّادِ يا تاجَ العُلا
// يا بَدرَ هَذا العَصرِ في كيوانِهِ
// يا مُخجِلاً نَوءَ السَماءِ بِجودِهِ
// يا مُنقِذَ المَحزونِ مِن أَحزانِهِ
// يا ساكِنينَ دِيارَ عَبسٍ إِنَّني
// لاقَيتُ مِن كِسرى وَمِن إِحسانِهِ
// ما لَيسَ يوصَفُ أَو يُقَدَّرُ أَو يَفي
// أَوصافَهُ أَحَدٌ بِوَصفِ لِسانِهِ
// مَلِكٌ حَوى رُتَبَ المَعالي كُلَّها
// بِسُمُوِّ مَجدٍ حَلَّ في إيوانِهِ
// مَولىً بِهِ شَرُفَ الزَمانُ وَأَهلُهُ
// وَالدَهرُ نالَ الفَخرَ مِن تيجانِهِ
// وَإِذا سَطا خافَ الأَنامَ جَميعُهُم
// مِن بأسه والليث عند عيانه
// المظهر الإنصاف في أيامه
// بخصاله والعدل في بلدانه
// أمسيت في ربع خصيب عنده
// متنزها فيه وفي بستانه
// ونظرت بركته تفيض وماؤه
// يحكي مواهبه وجود بنانه
// في مربع جمع الربيع بربعه
// من كل فن لاح في أفنانه
// وطيوره من كل نوع أنشدت
// جهرا بأن الدهر طوع عنانه
// ملك إذا ما جال في يوم اللقا
// وقف العدو محيرا في شانه
// والنصر من جلسائه دون الورى
// والسعد والإقبال من أعوانه
// فلأشكرن صنيعه بين الملا
// وأطاعن الفرسان في ميدانه