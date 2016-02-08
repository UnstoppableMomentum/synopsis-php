CREATE TABLE test
(
  id serial NOT NULL,
  int1 integer,
  int2 integer,
  CONSTRAINT test_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE test
  OWNER TO postgres;

