<?php

/**
 * @file
 * File with class CitiesMigration.
 */

/**
 * Class CitiesMigration.
 */
class CitiesMigration extends Migration {

  /**
   * CitiesMigration constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Source.
    $this->columns = array(
      0 => array('term_id', t('Term id')),
      1 => array('term_name', t('Term name')),
      2 => array('country_id', t('Country id')),
    );

    $this->source = new MigrateSourceCSV(
      'sites/default/files/cities.csv',
      $this->columns,
      array('delimiter' => ' ', 'header_rows' => 1));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'term_id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'description' => 'Term id',
          'alias' => 'import',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->destination = new MigrateDestinationTerm('cities');
    $this->addFieldMapping('name', 'term_name');

    $this->addFieldMapping('field_country', 'country_id')
      ->sourceMigration('Countries');
    $this->addFieldMapping('field_country:source_type')
      ->defaultValue('tid');

//    $this->addFieldMapping('field_country', 'country_id');
//    $this->addFieldMapping('field_country:create_term')
//      ->defaultValue(TRUE);
  }

}
