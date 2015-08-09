<?php

/**
 * Menu Callback function to generate list of questions.
 */
function question_list() {
  $query = new EntityFieldQuery;

  $query->entityCondition('entity_type', 'entityform')
    ->entityCondition('bundle', 'qa');

  $results = $query->execute();
  if (count($results['entityform']) > 0) {
    $question_rows = '';
    foreach ($results['entityform'] as $key => $entity) {
      $entityform_ids[$entity->entityform_id] = $entity->entityform_id;
      
      $entity_load = entityform_load($entity->entityform_id);
      $vars = array(
        'entityform_id' => $entity->entityform_id,
        'field_question' => !empty($entity_load->field_question[LANGUAGE_NONE][0]['value']) ? $entity_load->field_question[LANGUAGE_NONE][0]['value'] : '',
        'field_number_of_votes' => !empty($entity_load->field_number_of_votes[LANGUAGE_NONE][0]['value']) ? $entity_load->field_number_of_votes[LANGUAGE_NONE][0]['value'] : '',
        'field_number_of_answers' => !empty($entity_load->field_number_of_answers[LANGUAGE_NONE][0]['value']) ? $entity_load->field_number_of_answers[LANGUAGE_NONE][0]['value'] : '',
        'field_number_of_views' => !empty($entity_load->field_number_of_views[LANGUAGE_NONE][0]['value']) ? $entity_load->field_number_of_views[LANGUAGE_NONE][0]['value'] : ''
      );
      $question_rows .= theme('question_row', $vars);
      
    }
    $vars = array('question_rows' => $question_rows);
    $output['view'] = array(
      '#type' => 'markup',
      '#markup' => theme('question_list', $vars),
    );
  }
  return $output;
}
