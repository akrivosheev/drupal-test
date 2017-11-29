<?php

/**
 * @file
 * File with class CitiesMigration.
 */

/**
 * Class TermsMigration.
 */
abstract class TermsMigration extends Migration {
}
/**
 * Class CitiesMigration.
 */
class CitiesMigration extends TermsMigration {

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
      array('delimiter' => ',', 'header_rows' => 1));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'term_id' => array(
          'type' => 'int',
          'length' => 10,
          'not null' => TRUE,
          'unsigned' => TRUE,
          'description' => 'Term id',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->destination = new MigrateDestinationTerm('cities');

    $this->addFieldMapping('name', 'term_name');

    $this->addFieldMapping('field_country', 'country_id')
      ->sourceMigration('Cities');
    $this->addFieldMapping('field_country:source_type')
      ->defaultValue('tid');
  }

  /**
   * Function to update name.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->term_name = $row->term_name . ' - ' . $row->term_id;
    return TRUE;
  }

}
/**
 * Class CountriesMigration.
 */
class CountriesMigration extends TermsMigration {

  /**
   * CountriesMigration constructor.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // Source.
    $this->columns = array(
      0 => array('term_id', t('Term id')),
      1 => array('term_name', t('Term name')),
    );
    $this->source = new MigrateSourceCSV(
      'sites/default/files/countries.csv',
      $this->columns,
      array('delimiter' => ' ', 'header_rows' => 1));
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'term_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );
    $this->destination = new MigrateDestinationTerm('country');
    $this->addFieldMapping('name', 'term_name');
  }

}
