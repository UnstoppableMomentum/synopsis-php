-- Table: person

-- DROP TABLE person;

CREATE TABLE person
(
  id serial NOT NULL,
  name text,
  CONSTRAINT pk_person PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE person
  OWNER TO postgres;

