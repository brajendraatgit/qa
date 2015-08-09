# qa
Full Stack Drupal Developer Test

1) Clone/Download code from git repository (https://github.com/brajendraatgit/qa).
2) Find database dump copy named as question_database.sql from root directory.
3) Follow drupal site deployment process.
4) Admin credential is admin/admin.


Things that have been done for development -
  1) Question form and fields are entities instead of node.
  2) Validation for question field accept as "?" in the end, votes can be negative.
  3) Question list will appear on home page without no paging.
  4) View is not in use to create question list.
  5) Question list is created by custom module named "question_list" lacated in "sites/all/module/cusom" folder by using template files question-row.tpl.php and question-list.tpl.php.
  6) Site is developed in Drupal 7.
